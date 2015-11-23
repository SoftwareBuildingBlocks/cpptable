#pragma once
#include "expr.h"
#include "tokenizer.h"
#include "parser.h"

class expr_compiler
{
public:
	expr_compiler();
	~expr_compiler();
	bool init();
	bool eval(const std::string& sExpr, idata_row& dr);
	expr compile(const std::string& sExpr);
private:
	std::shared_ptr<parser> _p_parser;
	std::shared_ptr<tokenizer> _p_tokenizer;
};

