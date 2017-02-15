/*Auteur: PERCIE DU SERT Maxime
 *Date: 19/02/2016
 */
#ifndef INFO_H
#define INFO_H

#include <QString>
/*! \ingroup groupeNoyau
 * \brief Informations sur l'application.
 */
struct Info
{
public:
    //! Titre de l'application.
    static QString title()
        {return "Note";}
    //! Titre de fenêtre principale.
    static QString titleBox()
        {return title();}
};

#endif // INFO_H
