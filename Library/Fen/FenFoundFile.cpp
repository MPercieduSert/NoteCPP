#include "FenFoundFile.h"
#include "FenPrincipale.h"

FenFoundFile::FenFoundFile(FileInterface  *file, FenPrincipale *parent) : Fen(parent), m_ptr_file(file)
{

}

QString FenFoundFile::exists(bool copy)
{
    if(m_ptr_file->exists())
    {
        return m_ptr_file->fileName();
    }
    else
    {

        QString path(
                    foundFileMessage("Le fichier "+m_ptr_file->fileName()+" est introuvable. Souhaitez-vous le créer ou le trouver?",
                                     m_ptr_file->fileName(), m_ptr_file->fileExtension())
                    );
        if(path.isEmpty())
        {
            m_ptr_file->creer();
            return m_ptr_file->fileName();
        }
        else if(copy)
        {
            if(m_ptr_file->copy(path))
            {
                return m_ptr_file->fileName();
            }
            else
            {
                //throw std::runtime_error("Imposible d'effectuer la copie "+path.toStdString()+ "->"+m_ptr_file->fileName().toStdString());
                QMessageBox::critical(this,"Opération impossible","Imposible d'effectuer la copie " + path + "->" + m_ptr_file->fileName() + ".");
                return exists(copy);
            }
        }
        else
        {
            return path;
        }
    }
}

QString FenFoundFile::isValid(bool copy)
{
    if(m_ptr_file->isValid())
    {
        return m_ptr_file->fileName();
    }
    else
    {

        QString path(
                    foundFileMessage("Le fichier "+m_ptr_file->fileName()+" est invalide. Souhaitez-vous le recréer ou en trouver un autre trouver?",
                                     m_ptr_file->fileName(), m_ptr_file->fileExtension())
                    );
        if(path.isEmpty())
        {
            m_ptr_file->creer();
            return m_ptr_file->fileName();
        }
        else if(copy)
        {
            if(m_ptr_file->copy(path))
            {
                return m_ptr_file->fileName();
            }
            else
            {
                //throw std::runtime_error("Imposible d'effectuer la copie "+path.toStdString()+ "->"+m_ptr_file->fileName().toStdString());
                QMessageBox::critical(this,"Opération impossible","Imposible d'effectuer la copie " + path + "->" + m_ptr_file->fileName() + ".");
                return isValid(copy);
            }
        }
        else
        {
            return path;
        }
    }
}

void FenFoundFile::openInConf(const QString & path, bool save)
{
    //! Cherche l'entrée path dans le fichier de configuration
    //! et affiche une fenêtre de demande d'ouverture de fichier si l'entrée n'est pas présente.
    QString pathFile;
    bool exist = m_parent->config()->varExists(path);
    if(exist)
    {
        pathFile = m_parent->config()->getVars(path);
    }
    else
    {
        pathFile = foundFileMessage(QString("L'entrée suivante n'existe pas dans le fichier de configuration,\n")
                                    .append(path)
                                    .append("Pour que cette entrée soit créée dans le fichier de configuration,"
                                    " souhaitez-vous indiquer un fichier coorespondant ou que celui-ci soit créé?\n"),
                                    m_ptr_file->fileName(),
                                    m_ptr_file->fileExtension());
    }

    //! Si le chemin pathFile n'est pas vide il est enregistré par le gestionnaire de fichier,
    //! puis on test l'existence, la validité et l'ouverture du fichier.
    //! Ensuite si le chemin est valide, avec l'argument save=true l'entrée est enregistrée dans le fichier de configuration.
    if(!pathFile.isNull())
    {
        m_ptr_file->setFileName(pathFile);
        if(exist)
        {
            bool modif = false;
            while(!pathFile.isNull() && !(m_ptr_file->exists() && m_ptr_file->isValid() && m_ptr_file->open()))
            {
                pathFile = foundFileMessage(QString("L'entrée suivante dans le fichier de configuration est invalide,\n")
                                            .append(path)
                                            .append("Pour que cette entrée soit corrigé dans le fichier de configuration,"
                                            " souhaitez-vous indiquer un fichier coorespondant valide ou que celui-ci soit créé à nouveau?\n"),
                                            m_ptr_file->fileName(),
                                            m_ptr_file->fileExtension());
                if(!pathFile.isNull())
                {
                    m_ptr_file->setFileName(pathFile);
                    modif = true;
                }
            }
            if(modif && save)
            {
                m_parent->config()->modify(path,pathFile);
            }
        }
        else
        {
            while(!pathFile.isNull() && !(m_ptr_file->exists() && m_ptr_file->isValid() && m_ptr_file->open()))
            {
                pathFile = foundFileMessage("Le fichier indiqué est invalide, souhaitez-vous indiquer un autre fichier coorespondant valide"
                                            " ou que celui-ci soit créé?\n",
                                            m_ptr_file->fileName(), m_ptr_file->fileExtension());
                if(!pathFile.isNull())
                {
                    m_ptr_file->setFileName(pathFile);
                }
            }
            if(save && !pathFile.isNull())
            {
                m_parent->config()->add(path,pathFile);
            }
        }
    }

    //! Si le chemin est vide, un emplacement pour le nouveau fichier est demandé. Si le chemin est valide, avec l'argument save=true l'entrée est enregistrée dans le fichier de configuration.
    if(pathFile.isNull())
    {
        while(pathFile.isNull())
        {
            pathFile = QFileDialog::getSaveFileName(this,"Sous quel nom et à quel emplacement souhaitez-vous crée le fichier?",
                                                     m_parent->config()->getVars("conf/directories/default"),
                                                    m_ptr_file->fileExtension());
        }
        m_ptr_file->setFileName(pathFile);
        if(m_ptr_file->creer() && save)
        {
            m_parent->config()->add(path,pathFile);
        }
        else
        {
            QMessageBox::critical(this,"Opération impossible","Impossible de créé le fichier" + m_ptr_file->fileName() +".");
            throw std::runtime_error("Impossible de créé le fichier" + m_ptr_file->fileName().toStdString() +".");
        }
    }
}

// %%%%%%%%%%%%%%%%%%%%%% Protected %%%%%%%%%%%%%%%%%%%%%%%%%%%%

QString FenFoundFile::foundFileMessage(const QString & text, const QString & fileName, const QString & fileExtension, const QString & accept, const QString & reject, const QString & openText)
{
    if(!message(text,accept,reject))
    {
        QString path(QFileDialog::getOpenFileName(this,openText,fileName,fileExtension));
        if(path.isEmpty())
        {
            return foundFileMessage(text,fileName,fileExtension,accept,reject,openText);
        }
        else
        {
            return path;
        }
    }
    return QString();
}

/*QString FenFoundFile::inputToQString(const QString & path, const QMap<QString,QString> & atts)
{
    QString confInput(path);
    if(!atts.isEmpty())
    {
        confInput += "\navec les attributs: ";
        for(QMap<QString,QString>::const_iterator i = atts.cbegin(); i != atts.cend(); ++i) confInput += i.key() + " = " + i.value() + ",\n";
        confInput.chop(2);
    }
    confInput += ".\n";
    return confInput;
}*/

bool FenFoundFile::message(const QString &text, const QString &accept, const QString &reject)
{
   QMessageBox box(this);
   box.setText(text);
   QPushButton buttonAccept(accept,&box);
   box.addButton(&buttonAccept,QMessageBox::AcceptRole);
   QPushButton buttonReject(reject,&box);
   box.addButton(&buttonReject,QMessageBox::RejectRole);
   box.exec();
   return box.clickedButton() == &buttonAccept;
}
