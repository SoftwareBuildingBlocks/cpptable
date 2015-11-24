#include "query_interpreter.h"

#include <string>
#include "string_util.h"
#include <algorithm>
#include <regex>
#include "parser_symbol.h"
#include "data_row.h"

using namespace std;

query_interpreter::query_interpreter()
{
}


query_interpreter::~query_interpreter()
{
}


val query_interpreter::process_expression(parse_tree_node& symbol, idata_row& dr)
{
	auto& rhs = symbol.rhs();
	if (rhs->size() == 1)
	{
		return act_on_node(rhs->at(0), dr);
	}
	else if (rhs->size() == 3)
	{
		if (rhs->at(1).token.node_name == "OR")
		{
			auto left = act_on_node(rhs->at(0), dr);
			if (left.get<bool>() == true)
				return left;
			auto right = act_on_node(rhs->at(2), dr);
			return OR(left, right, dr);
		}
		else
		{
			throw runtime_error(format<128>("process_expression wrong child node"));
		}
		return val();
	}
	else
	{
		throw runtime_error(format<128>("process_expression wrong child size"));
	}
}

val query_interpreter::process_and(parse_tree_node&  symbol, idata_row& dr)
{
	auto& rhs = symbol.rhs();
	if (rhs->size() == 1)
	{
		return act_on_node(rhs->at(0), dr);
	}
	else if (rhs->size() == 3)
	{
		if (rhs->at(1).token.node_name == "AND")
		{
			auto left = act_on_node(rhs->at(0), dr);
			if (left.get<bool>() == false)
				return left;
			auto right = act_on_node(rhs->at(2), dr);
			return AND(left, right, dr);
		}
		else
		{
			throw runtime_error(format<128>("process_and wrong child node"));
		}
		return val();
	}
	else
	{
		throw runtime_error(format<128>("process_and wrong child size"));
	}
}

val query_interpreter::process_not(parse_tree_node&  symbol, idata_row& dr)
{
	auto& rhs = symbol.rhs();
	if (rhs->size() == 1)
	{
		return act_on_node(rhs->at(0), dr);
	}
	else if (rhs->size() == 2)
	{
		if (rhs->at(0).token.node_name == "NOT")
		{
			auto right = act_on_node(rhs->at(1), dr);
			return NOT(right, dr);
		}
		else
		{
			throw runtime_error(format<128>("process_not wrong child node"));
		}
		return val();
	}
	else
	{
		throw runtime_error(format<128>("process_not wrong child size"));
	}
}

val query_interpreter::process_pred(parse_tree_node&  symbol, idata_row& dr)
{
	auto& rhs = symbol.rhs();
	if (rhs->size() == 3 && rhs->at(1).token.node_name == ">")
	{
		auto left = act_on_node(rhs->at(0), dr);
		auto right = act_on_node(rhs->at(2), dr);
		return greater_than(left, right, dr);
	}
	else if (rhs->size() == 3 && rhs->at(1).token.node_name == "<")
	{
		auto left = act_on_node(rhs->at(0), dr);
		auto right = act_on_node(rhs->at(2), dr);
		return less_than(right, left, dr);
	}
	else if (rhs->size() == 3 && rhs->at(1).token.node_name == "=")
	{
		auto left = act_on_node(rhs->at(0), dr);
		auto right = act_on_node(rhs->at(2), dr);
		return equal_to(left, right, dr);
	}
	else if (rhs->size() == 3 && (rhs->at(1).token.node_name == "!=" || rhs->at(1).token.node_name == "<>"))
	{
		auto left = act_on_node(rhs->at(0), dr);
		auto right = act_on_node(rhs->at(2), dr);
		return not_equal_to(left, right, dr);
	}
	else if (rhs->size() == 3 && rhs->at(1).token.node_name == "<=")
	{
		auto left = act_on_node(rhs->at(0), dr);
		auto right = act_on_node(rhs->at(2), dr);
		return less_eq(left, right, dr);
	}
	else if (rhs->size() == 3 && rhs->at(1).token.node_name == ">=")
	{
		auto left = act_on_node(rhs->at(0), dr);
		auto right = act_on_node(rhs->at(2), dr);
		return greater_eq(left, right, dr);
	}
	else if (rhs->size() == 4 && rhs->at(1).token.node_name == "IS" && rhs->at(2).token.node_name == "NOT" && rhs->at(3).token.node_name == "NULL")
	{
		auto left = act_on_node(rhs->at(0), dr);
		return ISNOTNULL(left, dr);
	}
	else if (rhs->size() == 3 && rhs->at(1).token.node_name == "IS" && rhs->at(2).token.node_name == "NULL")
	{
		auto left = act_on_node(rhs->at(0), dr);
		return ISNULL(left, dr);
	}
	else if (rhs->size() == 3 && rhs->at(1).token.node_name == "IN")
	{
		auto left = act_on_node(rhs->at(0), dr);
		auto right = act_on_node(rhs->at(2), dr);
		return IN(left, right, dr);
	}
	else if (rhs->size() == 3 && rhs->at(1).token.node_name == "LIKE")
	{
		auto left = act_on_node(rhs->at(0), dr);
		auto right = act_on_node(rhs->at(2), dr);
		return LIKE(left, right, dr);
	}
	else if (rhs->size() == 1)
	{
		return act_on_node(rhs->at(0), dr);
	}
	else
	{
		throw runtime_error("Unknown Predicate: not yet implemented");
	}

	return val();
}

val query_interpreter::process_add(parse_tree_node&  symbol, idata_row& dr)
{
	auto& rhs = symbol.rhs();
	if (rhs->size() == 3 && rhs->at(1).token.node_name == "+")
	{
		auto left = act_on_node(rhs->at(0), dr);
		auto right = act_on_node(rhs->at(2), dr);
		return add(left, right, dr);
	}
	else if (rhs->size() == 3 && rhs->at(1).token.node_name == "-")
	{
		auto left = act_on_node(rhs->at(0), dr);
		auto right = act_on_node(rhs->at(2), dr);
		return subtract(left, right, dr);
	}
	else if (rhs->size() == 1)
	{
		return act_on_node(rhs->at(0), dr);
	}
	else
	{
		throw runtime_error("Unexpected branching of And Expression");
	}

	return val();
}

val query_interpreter::process_mult(parse_tree_node&  symbol, idata_row& dr)
{
	auto& rhs = symbol.rhs();
	if (rhs->size() == 3 && rhs->at(1).token.node_name == "*")
	{
		auto left = act_on_node(rhs->at(0), dr);
		auto right = act_on_node(rhs->at(2), dr);
		return multiply(right, left, dr);
	}
	else if (rhs->size() == 3 && rhs->at(1).token.node_name == "/")
	{
		auto left = act_on_node(rhs->at(0), dr);
		auto right = act_on_node(rhs->at(2), dr);
		return divide(right, left, dr);
	}
	else if (rhs->size() == 1)
	{
		return act_on_node(rhs->at(0), dr);
	}
	else
	{
		throw runtime_error("Unexpected branching of Mult Expression");
	}

	return val();
}

val query_interpreter::process_negate(parse_tree_node&  symbol, idata_row& dr)
{
	auto& rhs = symbol.rhs();
	if (rhs->size() == 2 && rhs->at(0).token.node_name == "-")
	{
		auto right = act_on_node(rhs->at(1), dr);
		return negate(right, dr);
	}
	else if (rhs->size() == 1)
	{
		return act_on_node(rhs->at(0), dr);
	}
	else
	{
		throw runtime_error("Unexpected branching of negate Expression");
	}

	return val();
}

val query_interpreter::process_id(parse_tree_node& symbol, idata_row& dr)
{
	auto idName = symbol.token.value;
	auto retval = dr[rtrim(ltrim(idName))];
	return retval;
}

val query_interpreter::process_value(parse_tree_node&  symbol, idata_row& dr)
{
	auto& rhs = symbol.rhs();
	if (rhs->size() == 1 && rhs->at(0).token.node_name == "IntegerLiteral")
	{
		auto& intTerm = rhs->at(0);
		return process_integer(intTerm, dr);
	}
	else if (rhs->size() == 1 && rhs->at(0).token.node_name == "Id")
	{
		auto& idTerm = rhs->at(0);
		return process_id(idTerm, dr);
	}
	else if (rhs->size() == 1 && rhs->at(0).token.node_name == "RealLiteral")
	{
		auto& idTerm = rhs->at(0);
		return process_double(idTerm, dr);
	}
	else if (rhs->size() == 1 && rhs->at(0).token.node_name == "StringLiteral")
	{
		auto& idTerm = rhs->at(0);
		return process_string(idTerm, dr);
	}
	else if (rhs->size() == 1 && rhs->at(0).token.node_name == "BoolLiteral")
	{
		auto& idTerm = rhs->at(0);
		return process_bool(idTerm, dr);
	}
	else if (rhs->size() == 1 && rhs->at(0).token.node_name == "NULL")
	{
		auto& idTerm = rhs->at(0);
		return process_null(idTerm, dr);
	}
	else if (rhs->size() == 1 && rhs->at(0).token.node_name == "Tuple")
	{
		return act_on_node(rhs->at(0), dr);
	}
	else
	{
		throw runtime_error(format<128>("Unexpected branching of process_value childcount:%d childname:%s"
										,rhs->size(),rhs->at(0).token.node_name.c_str()));
	}

	return val();
}

val query_interpreter::process_tuple(parse_tree_node&  symbol, idata_row& dr)
{
	auto& rhs = symbol.rhs();
	if (rhs->size() == 3 && rhs->at(0).token.node_name == "(" && rhs->at(2).token.node_name == ")")
	{
		return act_on_node(rhs->at(1), dr);
	}
	else
	{
		throw runtime_error("Tuple token does not match Tuple pattern");
	}
}

val query_interpreter::process_expr_list(parse_tree_node&  symbol, idata_row& dr)
{
	auto& rhs = symbol.rhs();
	if (rhs->size() == 3 && rhs->at(1).token.node_name == ",")
	{
		val left = act_on_node(rhs->at(0), dr);
		val right = act_on_node(rhs->at(2), dr);
		if (right.is<list<void*>>())
		{
			list<void*>& theList = right.get<list<void*>>();
			auto pleft = new val(left);
			theList.push_front(pleft);
			return right;
		}
		else
		{
			list<void*> newlist;
			auto pleft = new val(left);
			auto pright = new val(right);
			newlist.push_front(pright);
			newlist.push_front(pleft);
			return val().set<list<void*>>(newlist);
		}
	}
	else if (rhs->size() == 1)
	{
		return act_on_node(rhs->at(0), dr);
	}
	else
	{
		throw runtime_error("Tuple token does not match Tuple pattern");
	}
}

val query_interpreter::process_integer(parse_tree_node& symbol, idata_row& dr)
{
	auto res = stoi(symbol.token.value);
	val retval;
	retval.set<int>(res);
	return retval;
}

val query_interpreter::process_double(parse_tree_node& symbol, idata_row& dr)
{
	auto res = stod(symbol.token.value);
	val retval;
	retval.set<double>(res);
	return retval;
}

val query_interpreter::process_string(parse_tree_node& symbol, idata_row& dr)
{
	val retval;
	retval.set<string>(symbol.token.value);
	return retval;
}

val query_interpreter::process_bool(parse_tree_node& symbol, idata_row& dr)
{
	auto imageLower(symbol.token.value);
	transform(imageLower.begin(), imageLower.end(), imageLower.begin(), tolower);

	auto res = (imageLower == "true" ? true : false);
	val retval;
	retval.set<bool>(res);
	return retval;
}

val query_interpreter::process_null(parse_tree_node& terminal, idata_row& dr)
{
	return val();
}

val query_interpreter::act_on_node(parse_tree_node& symbol, idata_row& dr)
{
	if (symbol.token.node_name == "Expression") { return process_expression(symbol, dr); }
	else if (symbol.token.node_name == "And Exp") { return process_and(symbol, dr); }
	else if (symbol.token.node_name == "Not Exp") { return process_not(symbol, dr); }
	else if (symbol.token.node_name == "Pred Exp") { return process_pred(symbol, dr); }
	else if (symbol.token.node_name == "Add Exp") { return process_add(symbol, dr); }
	else if (symbol.token.node_name == "Mult Exp") { return process_mult(symbol, dr); }
	else if (symbol.token.node_name == "Negate Exp") { return process_negate(symbol, dr); }
	else if (symbol.token.node_name == "Value") { return process_value(symbol, dr); }
	else if (symbol.token.node_name == "Tuple") { return process_tuple(symbol, dr); }
	else if (symbol.token.node_name == "Expr List") { return process_expr_list(symbol, dr); }
	else if (symbol.token.node_name == "StringLiteral") { return process_string(symbol, dr); }
	else
	{
		throw runtime_error(format<128>("Unknown tok_symbol '%s'", symbol.token.node_name.c_str()));
	}
}

val query_interpreter::interpret(parse_tree_node& root, idata_row& dr)
{
	return act_on_node(root, dr);
}

val query_interpreter::greater_than(val& left, val& right, idata_row& dr)
{
	val retval;
	if (left.is<double>())
	{
		auto leftVal = left.get<double>();
		if (right.is<double>())
		{
			auto rightVal = right.get<double>();
			retval.set<bool>(leftVal > rightVal);
		}
		else if (right.is<int>())
		{
			auto rightVal = right.get<int>();
			retval.set<bool>(leftVal > rightVal);
		}
		else if (right.is<bool>())
		{
			auto rightVal = right.get<bool>();
			retval.set<bool>(leftVal > static_cast<int>(rightVal));
		}
		else if (!right.valid())
		{
			throw runtime_error("double cannot be compared Null.  Missing data or misspelled variable?");
		}
		else
		{
			throw runtime_error("double cannot be compared to this type");
		}
	}
	else if (left.is<int>())
	{
		auto leftVal = left.get<int>();
		if (right.is<double>())
		{
			auto rightVal = right.get<double>();
			retval.set<bool>(leftVal > rightVal);
		}
		else if (right.is<int>())
		{
			auto rightVal = right.get<int>();
			retval.set<bool>(leftVal > rightVal);
		}
		else if (right.is<bool>())
		{
			auto rightVal = right.get<bool>();
			retval.set<bool>(leftVal > static_cast<int>(rightVal));
		}
		else if (!right.valid())
		{
			throw runtime_error("int cannot be compared Null.  Missing data or misspelled variable?");
		}
		else
		{
			throw runtime_error("int cannot be compared to this type");
		}
	}
	else if (left.is<bool>())
	{
		auto leftVal = left.get<bool>();
		if (right.is<double>())
		{
			auto rightVal = right.get<double>();
			retval.set<bool>(leftVal?1:0 > rightVal);
		}
		else if (right.is<int>())
		{
			auto rightVal = right.get<int>();
			retval.set<bool>(leftVal?1:0 > rightVal);
		}
		else if (right.is<bool>())
		{
			auto rightVal = right.get<bool>();
			retval.set<bool>(leftVal > rightVal);
		}
		else if (!right.valid())
		{
			throw runtime_error("bool cannot be compared Null.  Missing data or misspelled variable?");
		}
		else
		{
			throw runtime_error("bool cannot be compared to this type");
		}
	}
	else if (left.is<string>())
	{
		auto leftVal = left.get<string>();
		if (right.is<string>())
		{
			auto rightVal = right.get<string>();
			rightVal = rightVal.substr(1, rightVal.length() - 2);
			retval.set<bool>(leftVal > rightVal);
		}
		else if (!right.valid())
		{
			throw runtime_error("string cannot be compared Null.  Missing data or misspelled variable?");
		}
		else
		{
			throw runtime_error("string cannot be compared to this type");
		}
	}
	else if (!left.valid())
	{
		throw runtime_error("Null cannot be compared in this manner.  Missing data or misspelled variable?");
	}
	else
	{
		throw runtime_error("greater_than not implmented for these types");
	}

	return retval;
}

val query_interpreter::less_than(val& left, val& right, idata_row& dr)
{
	// (5 < 20) is logically the same as (20 > 5)
	return greater_than(right, left, dr);
}

val query_interpreter::OR(val& left, val& right, idata_row& dr)
{
	auto leftval = left.get<bool>();
	auto rightval = right.get<bool>();

	val ret;
	ret.set<bool>(leftval || rightval);
	return ret;
}

val query_interpreter::AND(val& left, val& right, idata_row& dr)
{
	auto leftval = left.get<bool>();
	auto rightval = right.get<bool>();

	val ret;
	ret.set<bool>(leftval && rightval);
	return ret;
}

val query_interpreter::NOT(val& right, idata_row& dr)
{
	auto rightval = right.get<bool>();

	val ret;
	ret.set<bool>(!rightval);
	return ret;
}

val query_interpreter::equal_to(val& left, val& right, idata_row& dr)
{
	auto isGreater = greater_than(left, right, dr);

	if (isGreater.get<bool>())
		return val().set<bool>(false);

	auto isLess = less_than(left, right, dr);
	if (isLess.get<bool>())
		return val().set<bool>(false);

	return val().set<bool>(true);
}

val query_interpreter::not_equal_to(val& left, val& right, idata_row& dr)
{
	auto isEqual = equal_to(left, right, dr);
	return val().set<bool>(!isEqual.get<bool>());
}

val query_interpreter::less_eq(val& left, val& right, idata_row& dr)
{
	auto isGreater = greater_than(left, right, dr);
	if (isGreater.get<bool>())
		return val().set<bool>(false);

	return val().set<bool>(true);
}

val query_interpreter::greater_eq(val& left, val& right, idata_row& dr)
{
	auto isLess = less_than(left, right, dr);
	if (isLess.get<bool>())
		return val().set<bool>(false);

	return val().set<bool>(true);
}

val query_interpreter::ISNULL(val& left, idata_row& dr)
{
	if (!left.valid())
		return val().set<bool>(true);

	return val().set<bool>(false);
}

val query_interpreter::ISNOTNULL(val& left, idata_row& dr)
{
	if (left.valid())
		return val().set<bool>(true);

	return val().set<bool>(false);
}

val query_interpreter::add(val& left, val& right, idata_row& dr)
{
	val retval;
	if (left.is<double>())
	{
		auto leftVal = left.get<double>();
		if (right.is<double>())
		{
			auto rightVal = right.get<double>();
			retval.set<double>(leftVal + rightVal);
		}
		else if (right.is<int>())
		{
			auto rightVal = right.get<int>();
			retval.set<double>(leftVal + rightVal);
		}
		else if (!right.valid())
		{
			throw runtime_error("Cannot add Null.  Missing or misspelled variable?");
		}
		else
		{
			throw runtime_error("Cannot add non numeric data types");
		}
	}
	else if (left.is<int>())
	{
		auto leftVal = left.get<int>();
		if (right.is<double>())
		{
			auto rightVal = right.get<double>();
			retval.set<double>(leftVal + rightVal);
		}
		else if (!right.valid())
		{
			throw runtime_error("Cannot add Null.  Missing or misspelled variable?");
		}
		else
		{
			auto rightVal = right.get<int>();
			retval.set<int>(leftVal + rightVal);
		}
	}
	else if (!left.valid())
	{
		throw runtime_error("Cannot add Null.  Missing or misspelled variable?");
	}
	else
	{
		throw runtime_error("Cannot add non-int or double datatypes");
	}

	return retval;
}

val query_interpreter::subtract(val& left, val& right, idata_row& dr)
{
	if (right.is<int>())
	{
		return add(left, val().set<int>(-right.get<int>()), dr);
	}
	else if (right.is<double>())
	{
		return add(left, val().set<double>(-right.get<double>()), dr);
	}
	else if (!right.valid())
	{
		throw runtime_error("Cannot subtract Null.  Missing or misspelled variable?");
	}
	else
	{
		throw runtime_error("Unexpected type in subtract");
	}
}

val query_interpreter::multiply(val& right, val& left, idata_row& dr)
{
	val retval;
	if (left.is<double>())
	{
		auto leftVal = left.get<double>();
		if (right.is<double>())
		{
			auto rightVal = right.get<double>();
			retval.set<double>(leftVal * rightVal);
		}
		else
		{
			auto rightVal = right.get<int>();
			retval.set<double>(leftVal * rightVal);
		}
	}
	else if (left.is<int>())
	{
		auto leftVal = left.get<int>();
		if (right.is<double>())
		{
			auto rightVal = right.get<double>();
			retval.set<double>(leftVal * rightVal);
		}
		else
		{
			auto rightVal = right.get<int>();
			retval.set<int>(leftVal * rightVal);
		}
	}
	return retval;
}

val query_interpreter::divide(val& right, val& left, idata_row& dr)
{
	val retval;
	if (left.is<double>())
	{
		auto leftVal = left.get<double>();
		if (right.is<double>())
		{
			auto rightVal = right.get<double>();
			retval.set<double>(leftVal / rightVal);
		}
		else
		{
			auto rightVal = right.get<int>();
			retval.set<double>(leftVal / rightVal);
		}
	}
	else if (left.is<int>())
	{
		auto leftVal = left.get<int>();
		if (right.is<double>())
		{
			auto rightVal = right.get<double>();
			retval.set<double>(leftVal / rightVal);
		}
		else
		{
			auto rightVal = right.get<int>();
			retval.set<int>(leftVal / rightVal);
		}
	}
	return retval;
}

val query_interpreter::negate(val& right, idata_row& dr)
{
	if (right.is<int>())
		return val().set<int>(-right.get<int>());
	else if (right.is<double>())
		return val().set<double>(-right.get<double>());
	else
		throw runtime_error("Unexpected type in negate");
}

val query_interpreter::IN(val& left, val& right, idata_row& dr)
{
	if (right.is<list<void*>>())
	{
		auto valuecoll = right.get<list<void*>>();
		for (auto item : valuecoll)
		{
			auto& rightItem = *static_cast<val*>(item);
			if (equal_to(left, rightItem, dr).get<bool>())
			{
				for (auto tempitem : valuecoll)
				{
					auto tmpResultItem = static_cast<val*>(item);
					//					delete tmpResultItem;
				}
				return val().set<bool>(true);
			}
		}
		return val().set<bool>(false);
	}
	else
	{
		throw runtime_error("Left side of 'IN' expression must be an int,double,bool or string and right side must be a list");
	}
}

val query_interpreter::LIKE(val& left, val& right, idata_row& dr)
{
	auto rightCpy(right.get<string>());
	rightCpy = rightCpy.substr(1, rightCpy.length() - 2);
	str_replace(rightCpy, "%", ".*");
	str_replace(rightCpy, "_", ".");
	regex re(rightCpy.c_str());
	return val().set(regex_match(left.get<string>(), re));
}