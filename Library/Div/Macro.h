/*Auteur: PERCIE DU SERT Maxime
 *Date: 19/02/2016
 */
#ifndef MACRO_H
#define MACRO_H

/*! \defgroup groupeMacroBase Macro de base
 * \brief Ensemble des macros de base.
 */

// Classe
//! \ingroup groupeMacro
//! Macro déclarant par défaut les constructeurs et les opérateurs de copie et de déplacement.
#define CONSTR_AFFECT_DEFAUT(T) /*! Constructeur de recopie.*/ \
    T(const T & ) = default; \
    /*! Constructeur de déplacement.*/ \
    T(T && ) = default; \
    /*! Affectation par copie.*/ \
    T& operator = (const T &) = default; \
    /*! Affectation par déplacement.*/ \
    T& operator = (T &&) = default;

//! \ingroup groupeMacro
//! Macro déclarant le constructeur par défaut.
#define CONSTR_DEFAUT(T) /*! Constructeur par deffaut.*/ \
    T() = default;

//! \ingroup groupeMacro
//! Macro déclarant le destructeur vide.
#define DESTR_VIDE(T) /*! Destructeur vide.*/ \
    ~T() {}

#endif // MACRO_H
