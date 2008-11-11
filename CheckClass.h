/*
 * c++check - c/c++ syntax checking
 * Copyright (C) 2007 Daniel Marjamäki
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/
 */

//---------------------------------------------------------------------------
#ifndef CheckClassH
#define CheckClassH
//---------------------------------------------------------------------------

#include "tokenize.h"
#include <list>

struct VAR
{
    const char *name;
    bool        init;
    struct VAR *next;
};

class CheckClass
{
public:
    void CheckConstructors();

    void CheckUnusedPrivateFunctions();

    void CheckMemset();

    void CheckOperatorEq1();    // Warning upon "void operator=(.."

private:
    void ClassChecking_VarList_Initialize(const TOKEN *tok1, const TOKEN *ftok, struct VAR *varlist, const char classname[], std::list<std::string> &callstack);
    void InitVar(struct VAR *varlist, const char varname[]);
    const TOKEN *FindClassFunction( const TOKEN *tok, const char classname[], const char funcname[], int &indentlevel );
    struct VAR *ClassChecking_GetVarList(const TOKEN *tok1);
};
//---------------------------------------------------------------------------
#endif

