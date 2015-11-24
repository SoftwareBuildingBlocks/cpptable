#include <sstream>
#include "expr.h"
#include "token.h"
#include "string_util.h"
#include "parser.h"
#include "expr_compiler.h"
#include "tokenizer.h"

using namespace std;

expr_compiler::expr_compiler()
{
}


expr_compiler::~expr_compiler()
{
}

bool expr_compiler::init()
{
	_p_tokenizer = make_shared<tokenizer>();
	_p_tokenizer->init();

	_p_parser = make_shared<parser>();
	_p_parser->init();

	return true;
}

bool expr_compiler::eval(const string& sExpr, idata_row& dr)
{
	expr e = compile(sExpr);
	return e.eval(dr);
}

expr expr_compiler::compile(const string& str_expr)
{
	stringstream in(str_expr);
	vector<token> new_tokens;
	parse_tree_node root;

	try
	{
		new_tokens = _p_tokenizer->tokenize(in);
		root = _p_parser->parse(new_tokens);
	}
	catch(const runtime_error& e)
	{
		throw runtime_error(format<256>("Found errors while compiling expression. %s",e.what()));
	}

	return expr(root);
}