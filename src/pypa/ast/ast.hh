// Copyright 2014 Vinzenz Feenstra
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#ifndef GUARD_PYPA_AST_AST_HH_INCLUDED
#define GUARD_PYPA_AST_AST_HH_INCLUDED

#include <pypa/ast/base.hh>


namespace pypa {

PYPA_AST_EXPR(Expressions) {
    AstExprList items;
};

PYPA_AST_EXPR(Name) {
    AstContext  context;
    String      id;
};

PYPA_AST_EXPR(Keyword) {
    AstExpr name;
    AstExpr value;
};


PYPA_AST_EXPR(Alias) {
    AstExpr name;
    AstExpr as_name;
};

PYPA_AST_STMT(Assert) {
    AstExpr expression;
    AstExpr test;
};

PYPA_AST_STMT(Assign) {
    AstExpr targets;
    AstExpressions value; // since this can be chained tgt = value = value...
};

PYPA_AST_TYPE_DECL_DERIVED(Arguments) {
    AstExprList arguments;
    AstExprList defaults;
    AstExpr     kwargs;
    AstExprList args;
    AstExprList keywords;
};
DEF_AST_TYPE_BY_ID1(Arguments);

PYPA_AST_STMT(AugAssign) {
    AstExpr         value;
    AstExpr         target;
    AstBinOpType    op;
};

PYPA_AST_EXPR(Attribute) {
    AstExpr     value;
    AstContext  context;
    AstExpr     attribute;
};

PYPA_AST_EXPR(BinOp) {
    AstBinOpType    op;
    AstExpr         left;
    AstExpr         right;
};

PYPA_AST_EXPR(Bool) {
    bool value;
};

PYPA_AST_EXPR(BoolOp) {
    AstBoolOpType op;
    AstExprList   values;
};

PYPA_AST_STMT(Break) {};

PYPA_AST_EXPR(Call) {
    AstExpr      function;
    AstArguments arglist;
};

PYPA_AST_STMT(ClassDef) {
    AstExpr name;
    AstExpr bases;
    AstStmt body;
};

PYPA_AST_STMT(Continue) {};

PYPA_AST_EXPR(Compare) {
    AstExpr left;
    AstCompareOpType op;
    AstExpr right;
};

PYPA_AST_EXPR(Comprehension) {
    AstExpr target;
    AstExpr iter;
};
typedef AstComprehensionPtr      AstComprPtr;
typedef std::vector<AstComprPtr> AstComprList;

PYPA_AST_EXPR(Decorator) {
    AstExpr      name;
    AstArguments arguments;
};

PYPA_AST_EXPR(Decorators) {
    AstExprList decorators;
};

PYPA_AST_STMT(Decorated) {
    AstExpr decorators;
    AstStmt cls_or_fun_def;
};

PYPA_AST_STMT(Delete) {
    AstExpr targets;
};

PYPA_AST_EXPR(Dict) {
    AstExprList keys;
    AstExprList values;
};

PYPA_AST_EXPR(DictComp) {
    AstExpr key;
    AstExpr value;
    AstExpr generators;
};

PYPA_AST_TYPE_DECL_SLICE_KIND(Ellipsis) {};
DEF_AST_TYPE_BY_ID1(Ellipsis);

PYPA_AST_EXPR(ElseIf) {
    AstExpr test;
    AstStmt body;
};

PYPA_AST_STMT(Exec) {
    AstExpr body;
    AstExpr globals;
    AstExpr locals;
};

PYPA_AST_EXPR(Except) {
    AstExpr type;
    AstExpr name;
    AstStmt body;
};
typedef std::vector<AstExceptPtr> AstExceptList;

PYPA_AST_STMT(ExpressionStatement) {
    AstExpr expr;
};

PYPA_AST_TYPE_DECL_SLICE_KIND(ExtSlice) {
    AstSliceKindList dims;
};
DEF_AST_TYPE_BY_ID1(ExtSlice);

PYPA_AST_STMT(For) {
    AstStmt body;
    AstStmt orelse;
    AstExpr target;
    AstExpr iter;
};

PYPA_AST_EXPR(ForExpr) {
    AstExpr items;
    AstExpr generators;
    AstExpr iter;
};

PYPA_AST_STMT(FunctionDef) {
   AstExpr   name;
   AstArguments args;
   AstStmt      body;
};

PYPA_AST_EXPR(Generator) {
    AstExpr expression;
    AstExpr for_expr;
};

PYPA_AST_STMT(Global) {
    std::vector<AstNamePtr> names;
};

PYPA_AST_STMT(If) {
    AstStmt     body;
    AstExpr     elif;
    AstStmt     orelse;
    AstExpr     test;
};

PYPA_AST_EXPR(IfExpr) {
    AstExpr body;
    AstExpr orelse;
    AstExpr test;
};

PYPA_AST_TYPE_DECL_SLICE_KIND(Index) {
    AstExpr value;
};
DEF_AST_TYPE_BY_ID1(Index);

PYPA_AST_STMT(Import) {
    AstExpr names;
};

PYPA_AST_STMT(ImportFrom) {
    AstExpr         module;
    AstExpr         names;
    int             level;
};

PYPA_AST_EXPR(Lambda) {
    AstArguments    arguments;
    AstExpr         body;
};

PYPA_AST_EXPR(List) {
    AstExprList elements;
    AstContext  context;
};

PYPA_AST_EXPR(ListComp) {
    AstExpr generators;
    AstExpr element;
};

PYPA_AST_EXPR(None) {};

PYPA_AST_EXPR(Number) {
    enum Type {
        Integer,
        Float
    } num_type;
    union {
        double  floating;
        int64_t integer;
    };
};

PYPA_AST_TYPE_DECL_DERIVED(Module) {
    AstSuitePtr body;
};
DEF_AST_TYPE_BY_ID1(Module);

PYPA_AST_STMT(Pass) {
};

PYPA_AST_STMT(Print) {
    AstExpr         destination;
    bool            newline;
    AstExprList     values;
};


PYPA_AST_EXPR(Repr) {
    AstExpr value;
};

PYPA_AST_STMT(Raise) {
    AstExpr arg0;
    AstExpr arg1;
    AstExpr arg2;
};

PYPA_AST_STMT(Return) {
    AstExpr value;
};

PYPA_AST_EXPR(Set) {
    AstExprList elements;
};

PYPA_AST_EXPR(SetComp) {
    AstExpr element;
    AstExpr generators;
};

PYPA_AST_TYPE_DECL_SLICE_KIND(Slice) {
    AstExpr lower;
    AstExpr upper;
    AstExpr step;
};
DEF_AST_TYPE_BY_ID1(Slice);

PYPA_AST_EXPR(Str) {
    String value;
    AstContext context;
};

PYPA_AST_EXPR(Subscript) {
    AstExpr         value;
    AstSliceKindPtr slice;
    AstContext      context;
};

PYPA_AST_STMT(TryExcept) {
    AstStmt     body;
    AstStmt     orelse;
    AstExceptList   handlers;
};

PYPA_AST_STMT(TryFinally) {
    AstStmt body;
    AstStmt final_body;
};

PYPA_AST_EXPR(Tuple) {
    AstExprList elements;
    AstContext  context;
};

PYPA_AST_EXPR(UnaryOp) {
    AstExpr         operand;
    AstUnaryOpType  op;
};

PYPA_AST_STMT(While) {
    AstExpr test;
    AstStmt body;
    AstStmt orelse;
};

PYPA_AST_TYPE_DECL_DERIVED(WithItem) {
    AstExpr context;
    AstExpr optional;
};
DEF_AST_TYPE_BY_ID1(WithItem);

PYPA_AST_STMT(With) {
    AstWithItemList items;
    AstStmt         body;
};


PYPA_AST_EXPR(YieldExpr) {
    AstExpr args;
};

PYPA_AST_STMT(Yield) {
    AstExpr yield;
};

}
#endif // GUARD_PYPA_AST_AST_HH_INCLUDED
