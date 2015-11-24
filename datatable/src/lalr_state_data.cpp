#include "LALR_state_data.h"

std::map<int, production_rule> LALR_state_data::get_rules()
{
	std::map<int, production_rule> rules;
	
	{
		production_rule pr;
		pr.lhs = "Expression";
		pr.rhs.push_back("And Exp");
		pr.rhs.push_back("OR");
		pr.rhs.push_back("Expression");
		rules[0] = pr;
	}
	{
		production_rule pr;
		pr.lhs = "Expression";
		pr.rhs.push_back("And Exp");
		rules[1] = pr;
	}
	{
		production_rule pr;
		pr.lhs = "And Exp";
		pr.rhs.push_back("Not Exp");
		pr.rhs.push_back("AND");
		pr.rhs.push_back("And Exp");
		rules[2] = pr;
	}
	{
		production_rule pr;
		pr.lhs = "And Exp";
		pr.rhs.push_back("Not Exp");
		rules[3] = pr;
	}
	{
		production_rule pr;
		pr.lhs = "Not Exp";
		pr.rhs.push_back("NOT");
		pr.rhs.push_back("Pred Exp");
		rules[4] = pr;
	}
	{
		production_rule pr;
		pr.lhs = "Not Exp";
		pr.rhs.push_back("Pred Exp");
		rules[5] = pr;
	}
	{
		production_rule pr;
		pr.lhs = "Pred Exp";
		pr.rhs.push_back("Value");
		pr.rhs.push_back("IS");
		pr.rhs.push_back("NOT");
		pr.rhs.push_back("NULL");
		rules[6] = pr;
	}
	{
		production_rule pr;
		pr.lhs = "Pred Exp";
		pr.rhs.push_back("Value");
		pr.rhs.push_back("IS");
		pr.rhs.push_back("NULL");
		rules[7] = pr;
	}
	{
		production_rule pr;
		pr.lhs = "Pred Exp";
		pr.rhs.push_back("Add Exp");
		pr.rhs.push_back("LIKE");
		pr.rhs.push_back("StringLiteral");
		rules[8] = pr;
	}
	{
		production_rule pr;
		pr.lhs = "Pred Exp";
		pr.rhs.push_back("Add Exp");
		pr.rhs.push_back("IN");
		pr.rhs.push_back("Tuple");
		rules[9] = pr;
	}
	{
		production_rule pr;
		pr.lhs = "Pred Exp";
		pr.rhs.push_back("Add Exp");
		pr.rhs.push_back("=");
		pr.rhs.push_back("Add Exp");
		rules[10] = pr;
	}
	{
		production_rule pr;
		pr.lhs = "Pred Exp";
		pr.rhs.push_back("Add Exp");
		pr.rhs.push_back("<>");
		pr.rhs.push_back("Add Exp");
		rules[11] = pr;
	}
	{
		production_rule pr;
		pr.lhs = "Pred Exp";
		pr.rhs.push_back("Add Exp");
		pr.rhs.push_back("!=");
		pr.rhs.push_back("Add Exp");
		rules[12] = pr;
	}
	{
		production_rule pr;
		pr.lhs = "Pred Exp";
		pr.rhs.push_back("Add Exp");
		pr.rhs.push_back(">");
		pr.rhs.push_back("Add Exp");
		rules[13] = pr;
	}
	{
		production_rule pr;
		pr.lhs = "Pred Exp";
		pr.rhs.push_back("Add Exp");
		pr.rhs.push_back(">=");
		pr.rhs.push_back("Add Exp");
		rules[14] = pr;
	}
	{
		production_rule pr;
		pr.lhs = "Pred Exp";
		pr.rhs.push_back("Add Exp");
		pr.rhs.push_back("<");
		pr.rhs.push_back("Add Exp");
		rules[15] = pr;
	}
	{
		production_rule pr;
		pr.lhs = "Pred Exp";
		pr.rhs.push_back("Add Exp");
		pr.rhs.push_back("<=");
		pr.rhs.push_back("Add Exp");
		rules[16] = pr;
	}
	{
		production_rule pr;
		pr.lhs = "Pred Exp";
		pr.rhs.push_back("Add Exp");
		rules[17] = pr;
	}
	{
		production_rule pr;
		pr.lhs = "Add Exp";
		pr.rhs.push_back("Add Exp");
		pr.rhs.push_back("+");
		pr.rhs.push_back("Mult Exp");
		rules[18] = pr;
	}
	{
		production_rule pr;
		pr.lhs = "Add Exp";
		pr.rhs.push_back("Add Exp");
		pr.rhs.push_back("-");
		pr.rhs.push_back("Mult Exp");
		rules[19] = pr;
	}
	{
		production_rule pr;
		pr.lhs = "Add Exp";
		pr.rhs.push_back("Mult Exp");
		rules[20] = pr;
	}
	{
		production_rule pr;
		pr.lhs = "Mult Exp";
		pr.rhs.push_back("Mult Exp");
		pr.rhs.push_back("*");
		pr.rhs.push_back("Negate Exp");
		rules[21] = pr;
	}
	{
		production_rule pr;
		pr.lhs = "Mult Exp";
		pr.rhs.push_back("Mult Exp");
		pr.rhs.push_back("/");
		pr.rhs.push_back("Negate Exp");
		rules[22] = pr;
	}
	{
		production_rule pr;
		pr.lhs = "Mult Exp";
		pr.rhs.push_back("Negate Exp");
		rules[23] = pr;
	}
	{
		production_rule pr;
		pr.lhs = "Negate Exp";
		pr.rhs.push_back("-");
		pr.rhs.push_back("Value");
		rules[24] = pr;
	}
	{
		production_rule pr;
		pr.lhs = "Negate Exp";
		pr.rhs.push_back("Value");
		rules[25] = pr;
	}
	{
		production_rule pr;
		pr.lhs = "Value";
		pr.rhs.push_back("Tuple");
		rules[26] = pr;
	}
	{
		production_rule pr;
		pr.lhs = "Value";
		pr.rhs.push_back("Id");
		rules[27] = pr;
	}
	{
		production_rule pr;
		pr.lhs = "Value";
		pr.rhs.push_back("IntegerLiteral");
		rules[28] = pr;
	}
	{
		production_rule pr;
		pr.lhs = "Value";
		pr.rhs.push_back("RealLiteral");
		rules[29] = pr;
	}
	{
		production_rule pr;
		pr.lhs = "Value";
		pr.rhs.push_back("StringLiteral");
		rules[30] = pr;
	}
	{
		production_rule pr;
		pr.lhs = "Value";
		pr.rhs.push_back("BoolLiteral");
		rules[31] = pr;
	}
	{
		production_rule pr;
		pr.lhs = "Value";
		pr.rhs.push_back("NULL");
		rules[32] = pr;
	}
	{
		production_rule pr;
		pr.lhs = "Tuple";
		pr.rhs.push_back("(");
		pr.rhs.push_back("Expr List");
		pr.rhs.push_back(")");
		rules[33] = pr;
	}
	{
		production_rule pr;
		pr.lhs = "Expr List";
		pr.rhs.push_back("Expression");
		pr.rhs.push_back(",");
		pr.rhs.push_back("Expr List");
		rules[34] = pr;
	}
	{
		production_rule pr;
		pr.lhs = "Expr List";
		pr.rhs.push_back("Expression");
		rules[35] = pr;
	}

	return rules;
}


std::map<int, parser_state> LALR_state_data::get_states()
{
	std::map<int, parser_state> states;

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 1;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["-"] = a;
		}
		{
			parser_action a;
			a.action_idx = 2;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["("] = a;
		}
		{
			parser_action a;
			a.action_idx = 3;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["BoolLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 4;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["Id"] = a;
		}
		{
			parser_action a;
			a.action_idx = 5;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["IntegerLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 6;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["NOT"] = a;
		}
		{
			parser_action a;
			a.action_idx = 7;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["NULL"] = a;
		}
		{
			parser_action a;
			a.action_idx = 8;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["RealLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 9;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["StringLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 10;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Add Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 11;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["And Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 12;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Expression"] = a;
		}
		{
			parser_action a;
			a.action_idx = 13;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Mult Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 14;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Negate Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 15;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Not Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 16;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Pred Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 17;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Tuple"] = a;
		}
		{
			parser_action a;
			a.action_idx = 18;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Value"] = a;
		}
		states[0] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 2;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["("] = a;
		}
		{
			parser_action a;
			a.action_idx = 3;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["BoolLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 4;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["Id"] = a;
		}
		{
			parser_action a;
			a.action_idx = 5;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["IntegerLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 7;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["NULL"] = a;
		}
		{
			parser_action a;
			a.action_idx = 8;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["RealLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 9;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["StringLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 17;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Tuple"] = a;
		}
		{
			parser_action a;
			a.action_idx = 19;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Value"] = a;
		}
		states[1] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 1;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["-"] = a;
		}
		{
			parser_action a;
			a.action_idx = 2;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["("] = a;
		}
		{
			parser_action a;
			a.action_idx = 3;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["BoolLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 4;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["Id"] = a;
		}
		{
			parser_action a;
			a.action_idx = 5;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["IntegerLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 6;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["NOT"] = a;
		}
		{
			parser_action a;
			a.action_idx = 7;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["NULL"] = a;
		}
		{
			parser_action a;
			a.action_idx = 8;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["RealLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 9;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["StringLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 10;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Add Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 11;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["And Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 20;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Expr List"] = a;
		}
		{
			parser_action a;
			a.action_idx = 21;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Expression"] = a;
		}
		{
			parser_action a;
			a.action_idx = 13;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Mult Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 14;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Negate Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 15;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Not Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 16;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Pred Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 17;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Tuple"] = a;
		}
		{
			parser_action a;
			a.action_idx = 18;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Value"] = a;
		}
		states[2] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 31;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["EOF"] = a;
		}
		{
			parser_action a;
			a.action_idx = 31;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["-"] = a;
		}
		{
			parser_action a;
			a.action_idx = 31;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["!="] = a;
		}
		{
			parser_action a;
			a.action_idx = 31;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[")"] = a;
		}
		{
			parser_action a;
			a.action_idx = 31;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["*"] = a;
		}
		{
			parser_action a;
			a.action_idx = 31;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[","] = a;
		}
		{
			parser_action a;
			a.action_idx = 31;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["/"] = a;
		}
		{
			parser_action a;
			a.action_idx = 31;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["+"] = a;
		}
		{
			parser_action a;
			a.action_idx = 31;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<"] = a;
		}
		{
			parser_action a;
			a.action_idx = 31;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<="] = a;
		}
		{
			parser_action a;
			a.action_idx = 31;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<>"] = a;
		}
		{
			parser_action a;
			a.action_idx = 31;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["="] = a;
		}
		{
			parser_action a;
			a.action_idx = 31;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[">"] = a;
		}
		{
			parser_action a;
			a.action_idx = 31;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[">="] = a;
		}
		{
			parser_action a;
			a.action_idx = 31;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["AND"] = a;
		}
		{
			parser_action a;
			a.action_idx = 31;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["IN"] = a;
		}
		{
			parser_action a;
			a.action_idx = 31;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["IS"] = a;
		}
		{
			parser_action a;
			a.action_idx = 31;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["LIKE"] = a;
		}
		{
			parser_action a;
			a.action_idx = 31;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["OR"] = a;
		}
		states[3] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 27;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["EOF"] = a;
		}
		{
			parser_action a;
			a.action_idx = 27;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["-"] = a;
		}
		{
			parser_action a;
			a.action_idx = 27;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["!="] = a;
		}
		{
			parser_action a;
			a.action_idx = 27;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[")"] = a;
		}
		{
			parser_action a;
			a.action_idx = 27;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["*"] = a;
		}
		{
			parser_action a;
			a.action_idx = 27;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[","] = a;
		}
		{
			parser_action a;
			a.action_idx = 27;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["/"] = a;
		}
		{
			parser_action a;
			a.action_idx = 27;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["+"] = a;
		}
		{
			parser_action a;
			a.action_idx = 27;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<"] = a;
		}
		{
			parser_action a;
			a.action_idx = 27;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<="] = a;
		}
		{
			parser_action a;
			a.action_idx = 27;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<>"] = a;
		}
		{
			parser_action a;
			a.action_idx = 27;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["="] = a;
		}
		{
			parser_action a;
			a.action_idx = 27;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[">"] = a;
		}
		{
			parser_action a;
			a.action_idx = 27;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[">="] = a;
		}
		{
			parser_action a;
			a.action_idx = 27;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["AND"] = a;
		}
		{
			parser_action a;
			a.action_idx = 27;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["IN"] = a;
		}
		{
			parser_action a;
			a.action_idx = 27;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["IS"] = a;
		}
		{
			parser_action a;
			a.action_idx = 27;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["LIKE"] = a;
		}
		{
			parser_action a;
			a.action_idx = 27;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["OR"] = a;
		}
		states[4] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 28;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["EOF"] = a;
		}
		{
			parser_action a;
			a.action_idx = 28;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["-"] = a;
		}
		{
			parser_action a;
			a.action_idx = 28;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["!="] = a;
		}
		{
			parser_action a;
			a.action_idx = 28;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[")"] = a;
		}
		{
			parser_action a;
			a.action_idx = 28;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["*"] = a;
		}
		{
			parser_action a;
			a.action_idx = 28;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[","] = a;
		}
		{
			parser_action a;
			a.action_idx = 28;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["/"] = a;
		}
		{
			parser_action a;
			a.action_idx = 28;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["+"] = a;
		}
		{
			parser_action a;
			a.action_idx = 28;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<"] = a;
		}
		{
			parser_action a;
			a.action_idx = 28;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<="] = a;
		}
		{
			parser_action a;
			a.action_idx = 28;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<>"] = a;
		}
		{
			parser_action a;
			a.action_idx = 28;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["="] = a;
		}
		{
			parser_action a;
			a.action_idx = 28;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[">"] = a;
		}
		{
			parser_action a;
			a.action_idx = 28;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[">="] = a;
		}
		{
			parser_action a;
			a.action_idx = 28;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["AND"] = a;
		}
		{
			parser_action a;
			a.action_idx = 28;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["IN"] = a;
		}
		{
			parser_action a;
			a.action_idx = 28;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["IS"] = a;
		}
		{
			parser_action a;
			a.action_idx = 28;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["LIKE"] = a;
		}
		{
			parser_action a;
			a.action_idx = 28;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["OR"] = a;
		}
		states[5] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 1;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["-"] = a;
		}
		{
			parser_action a;
			a.action_idx = 2;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["("] = a;
		}
		{
			parser_action a;
			a.action_idx = 3;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["BoolLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 4;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["Id"] = a;
		}
		{
			parser_action a;
			a.action_idx = 5;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["IntegerLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 7;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["NULL"] = a;
		}
		{
			parser_action a;
			a.action_idx = 8;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["RealLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 9;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["StringLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 10;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Add Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 13;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Mult Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 14;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Negate Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 22;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Pred Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 17;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Tuple"] = a;
		}
		{
			parser_action a;
			a.action_idx = 18;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Value"] = a;
		}
		states[6] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 32;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["EOF"] = a;
		}
		{
			parser_action a;
			a.action_idx = 32;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["-"] = a;
		}
		{
			parser_action a;
			a.action_idx = 32;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["!="] = a;
		}
		{
			parser_action a;
			a.action_idx = 32;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[")"] = a;
		}
		{
			parser_action a;
			a.action_idx = 32;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["*"] = a;
		}
		{
			parser_action a;
			a.action_idx = 32;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[","] = a;
		}
		{
			parser_action a;
			a.action_idx = 32;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["/"] = a;
		}
		{
			parser_action a;
			a.action_idx = 32;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["+"] = a;
		}
		{
			parser_action a;
			a.action_idx = 32;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<"] = a;
		}
		{
			parser_action a;
			a.action_idx = 32;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<="] = a;
		}
		{
			parser_action a;
			a.action_idx = 32;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<>"] = a;
		}
		{
			parser_action a;
			a.action_idx = 32;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["="] = a;
		}
		{
			parser_action a;
			a.action_idx = 32;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[">"] = a;
		}
		{
			parser_action a;
			a.action_idx = 32;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[">="] = a;
		}
		{
			parser_action a;
			a.action_idx = 32;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["AND"] = a;
		}
		{
			parser_action a;
			a.action_idx = 32;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["IN"] = a;
		}
		{
			parser_action a;
			a.action_idx = 32;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["IS"] = a;
		}
		{
			parser_action a;
			a.action_idx = 32;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["LIKE"] = a;
		}
		{
			parser_action a;
			a.action_idx = 32;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["OR"] = a;
		}
		states[7] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 29;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["EOF"] = a;
		}
		{
			parser_action a;
			a.action_idx = 29;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["-"] = a;
		}
		{
			parser_action a;
			a.action_idx = 29;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["!="] = a;
		}
		{
			parser_action a;
			a.action_idx = 29;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[")"] = a;
		}
		{
			parser_action a;
			a.action_idx = 29;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["*"] = a;
		}
		{
			parser_action a;
			a.action_idx = 29;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[","] = a;
		}
		{
			parser_action a;
			a.action_idx = 29;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["/"] = a;
		}
		{
			parser_action a;
			a.action_idx = 29;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["+"] = a;
		}
		{
			parser_action a;
			a.action_idx = 29;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<"] = a;
		}
		{
			parser_action a;
			a.action_idx = 29;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<="] = a;
		}
		{
			parser_action a;
			a.action_idx = 29;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<>"] = a;
		}
		{
			parser_action a;
			a.action_idx = 29;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["="] = a;
		}
		{
			parser_action a;
			a.action_idx = 29;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[">"] = a;
		}
		{
			parser_action a;
			a.action_idx = 29;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[">="] = a;
		}
		{
			parser_action a;
			a.action_idx = 29;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["AND"] = a;
		}
		{
			parser_action a;
			a.action_idx = 29;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["IN"] = a;
		}
		{
			parser_action a;
			a.action_idx = 29;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["IS"] = a;
		}
		{
			parser_action a;
			a.action_idx = 29;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["LIKE"] = a;
		}
		{
			parser_action a;
			a.action_idx = 29;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["OR"] = a;
		}
		states[8] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 30;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["EOF"] = a;
		}
		{
			parser_action a;
			a.action_idx = 30;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["-"] = a;
		}
		{
			parser_action a;
			a.action_idx = 30;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["!="] = a;
		}
		{
			parser_action a;
			a.action_idx = 30;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[")"] = a;
		}
		{
			parser_action a;
			a.action_idx = 30;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["*"] = a;
		}
		{
			parser_action a;
			a.action_idx = 30;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[","] = a;
		}
		{
			parser_action a;
			a.action_idx = 30;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["/"] = a;
		}
		{
			parser_action a;
			a.action_idx = 30;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["+"] = a;
		}
		{
			parser_action a;
			a.action_idx = 30;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<"] = a;
		}
		{
			parser_action a;
			a.action_idx = 30;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<="] = a;
		}
		{
			parser_action a;
			a.action_idx = 30;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<>"] = a;
		}
		{
			parser_action a;
			a.action_idx = 30;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["="] = a;
		}
		{
			parser_action a;
			a.action_idx = 30;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[">"] = a;
		}
		{
			parser_action a;
			a.action_idx = 30;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[">="] = a;
		}
		{
			parser_action a;
			a.action_idx = 30;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["AND"] = a;
		}
		{
			parser_action a;
			a.action_idx = 30;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["IN"] = a;
		}
		{
			parser_action a;
			a.action_idx = 30;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["IS"] = a;
		}
		{
			parser_action a;
			a.action_idx = 30;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["LIKE"] = a;
		}
		{
			parser_action a;
			a.action_idx = 30;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["OR"] = a;
		}
		states[9] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 23;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["-"] = a;
		}
		{
			parser_action a;
			a.action_idx = 24;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["!="] = a;
		}
		{
			parser_action a;
			a.action_idx = 25;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["+"] = a;
		}
		{
			parser_action a;
			a.action_idx = 26;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["<"] = a;
		}
		{
			parser_action a;
			a.action_idx = 27;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["<="] = a;
		}
		{
			parser_action a;
			a.action_idx = 28;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["<>"] = a;
		}
		{
			parser_action a;
			a.action_idx = 29;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["="] = a;
		}
		{
			parser_action a;
			a.action_idx = 30;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions[">"] = a;
		}
		{
			parser_action a;
			a.action_idx = 31;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions[">="] = a;
		}
		{
			parser_action a;
			a.action_idx = 32;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["IN"] = a;
		}
		{
			parser_action a;
			a.action_idx = 33;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["LIKE"] = a;
		}
		{
			parser_action a;
			a.action_idx = 17;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["EOF"] = a;
		}
		{
			parser_action a;
			a.action_idx = 17;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[")"] = a;
		}
		{
			parser_action a;
			a.action_idx = 17;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[","] = a;
		}
		{
			parser_action a;
			a.action_idx = 17;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["AND"] = a;
		}
		{
			parser_action a;
			a.action_idx = 17;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["OR"] = a;
		}
		states[10] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 34;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["OR"] = a;
		}
		{
			parser_action a;
			a.action_idx = 1;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["EOF"] = a;
		}
		{
			parser_action a;
			a.action_idx = 1;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[")"] = a;
		}
		{
			parser_action a;
			a.action_idx = 1;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[","] = a;
		}
		states[11] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 35;
			a.action = parser_action::SHIFT_REDUCE::ACCEPT;
			st.actions["EOF"] = a;
		}
		states[12] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 35;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["*"] = a;
		}
		{
			parser_action a;
			a.action_idx = 36;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["/"] = a;
		}
		{
			parser_action a;
			a.action_idx = 20;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["EOF"] = a;
		}
		{
			parser_action a;
			a.action_idx = 20;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["-"] = a;
		}
		{
			parser_action a;
			a.action_idx = 20;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["!="] = a;
		}
		{
			parser_action a;
			a.action_idx = 20;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[")"] = a;
		}
		{
			parser_action a;
			a.action_idx = 20;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[","] = a;
		}
		{
			parser_action a;
			a.action_idx = 20;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["+"] = a;
		}
		{
			parser_action a;
			a.action_idx = 20;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<"] = a;
		}
		{
			parser_action a;
			a.action_idx = 20;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<="] = a;
		}
		{
			parser_action a;
			a.action_idx = 20;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<>"] = a;
		}
		{
			parser_action a;
			a.action_idx = 20;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["="] = a;
		}
		{
			parser_action a;
			a.action_idx = 20;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[">"] = a;
		}
		{
			parser_action a;
			a.action_idx = 20;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[">="] = a;
		}
		{
			parser_action a;
			a.action_idx = 20;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["AND"] = a;
		}
		{
			parser_action a;
			a.action_idx = 20;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["IN"] = a;
		}
		{
			parser_action a;
			a.action_idx = 20;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["LIKE"] = a;
		}
		{
			parser_action a;
			a.action_idx = 20;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["OR"] = a;
		}
		states[13] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 23;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["EOF"] = a;
		}
		{
			parser_action a;
			a.action_idx = 23;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["-"] = a;
		}
		{
			parser_action a;
			a.action_idx = 23;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["!="] = a;
		}
		{
			parser_action a;
			a.action_idx = 23;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[")"] = a;
		}
		{
			parser_action a;
			a.action_idx = 23;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["*"] = a;
		}
		{
			parser_action a;
			a.action_idx = 23;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[","] = a;
		}
		{
			parser_action a;
			a.action_idx = 23;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["/"] = a;
		}
		{
			parser_action a;
			a.action_idx = 23;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["+"] = a;
		}
		{
			parser_action a;
			a.action_idx = 23;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<"] = a;
		}
		{
			parser_action a;
			a.action_idx = 23;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<="] = a;
		}
		{
			parser_action a;
			a.action_idx = 23;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<>"] = a;
		}
		{
			parser_action a;
			a.action_idx = 23;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["="] = a;
		}
		{
			parser_action a;
			a.action_idx = 23;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[">"] = a;
		}
		{
			parser_action a;
			a.action_idx = 23;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[">="] = a;
		}
		{
			parser_action a;
			a.action_idx = 23;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["AND"] = a;
		}
		{
			parser_action a;
			a.action_idx = 23;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["IN"] = a;
		}
		{
			parser_action a;
			a.action_idx = 23;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["LIKE"] = a;
		}
		{
			parser_action a;
			a.action_idx = 23;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["OR"] = a;
		}
		states[14] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 37;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["AND"] = a;
		}
		{
			parser_action a;
			a.action_idx = 3;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["EOF"] = a;
		}
		{
			parser_action a;
			a.action_idx = 3;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[")"] = a;
		}
		{
			parser_action a;
			a.action_idx = 3;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[","] = a;
		}
		{
			parser_action a;
			a.action_idx = 3;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["OR"] = a;
		}
		states[15] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 5;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["EOF"] = a;
		}
		{
			parser_action a;
			a.action_idx = 5;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[")"] = a;
		}
		{
			parser_action a;
			a.action_idx = 5;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[","] = a;
		}
		{
			parser_action a;
			a.action_idx = 5;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["AND"] = a;
		}
		{
			parser_action a;
			a.action_idx = 5;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["OR"] = a;
		}
		states[16] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 26;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["EOF"] = a;
		}
		{
			parser_action a;
			a.action_idx = 26;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["-"] = a;
		}
		{
			parser_action a;
			a.action_idx = 26;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["!="] = a;
		}
		{
			parser_action a;
			a.action_idx = 26;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[")"] = a;
		}
		{
			parser_action a;
			a.action_idx = 26;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["*"] = a;
		}
		{
			parser_action a;
			a.action_idx = 26;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[","] = a;
		}
		{
			parser_action a;
			a.action_idx = 26;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["/"] = a;
		}
		{
			parser_action a;
			a.action_idx = 26;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["+"] = a;
		}
		{
			parser_action a;
			a.action_idx = 26;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<"] = a;
		}
		{
			parser_action a;
			a.action_idx = 26;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<="] = a;
		}
		{
			parser_action a;
			a.action_idx = 26;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<>"] = a;
		}
		{
			parser_action a;
			a.action_idx = 26;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["="] = a;
		}
		{
			parser_action a;
			a.action_idx = 26;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[">"] = a;
		}
		{
			parser_action a;
			a.action_idx = 26;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[">="] = a;
		}
		{
			parser_action a;
			a.action_idx = 26;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["AND"] = a;
		}
		{
			parser_action a;
			a.action_idx = 26;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["IN"] = a;
		}
		{
			parser_action a;
			a.action_idx = 26;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["IS"] = a;
		}
		{
			parser_action a;
			a.action_idx = 26;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["LIKE"] = a;
		}
		{
			parser_action a;
			a.action_idx = 26;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["OR"] = a;
		}
		states[17] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 38;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["IS"] = a;
		}
		{
			parser_action a;
			a.action_idx = 25;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["EOF"] = a;
		}
		{
			parser_action a;
			a.action_idx = 25;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["-"] = a;
		}
		{
			parser_action a;
			a.action_idx = 25;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["!="] = a;
		}
		{
			parser_action a;
			a.action_idx = 25;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[")"] = a;
		}
		{
			parser_action a;
			a.action_idx = 25;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["*"] = a;
		}
		{
			parser_action a;
			a.action_idx = 25;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[","] = a;
		}
		{
			parser_action a;
			a.action_idx = 25;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["/"] = a;
		}
		{
			parser_action a;
			a.action_idx = 25;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["+"] = a;
		}
		{
			parser_action a;
			a.action_idx = 25;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<"] = a;
		}
		{
			parser_action a;
			a.action_idx = 25;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<="] = a;
		}
		{
			parser_action a;
			a.action_idx = 25;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<>"] = a;
		}
		{
			parser_action a;
			a.action_idx = 25;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["="] = a;
		}
		{
			parser_action a;
			a.action_idx = 25;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[">"] = a;
		}
		{
			parser_action a;
			a.action_idx = 25;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[">="] = a;
		}
		{
			parser_action a;
			a.action_idx = 25;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["AND"] = a;
		}
		{
			parser_action a;
			a.action_idx = 25;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["IN"] = a;
		}
		{
			parser_action a;
			a.action_idx = 25;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["LIKE"] = a;
		}
		{
			parser_action a;
			a.action_idx = 25;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["OR"] = a;
		}
		states[18] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 24;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["EOF"] = a;
		}
		{
			parser_action a;
			a.action_idx = 24;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["-"] = a;
		}
		{
			parser_action a;
			a.action_idx = 24;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["!="] = a;
		}
		{
			parser_action a;
			a.action_idx = 24;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[")"] = a;
		}
		{
			parser_action a;
			a.action_idx = 24;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["*"] = a;
		}
		{
			parser_action a;
			a.action_idx = 24;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[","] = a;
		}
		{
			parser_action a;
			a.action_idx = 24;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["/"] = a;
		}
		{
			parser_action a;
			a.action_idx = 24;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["+"] = a;
		}
		{
			parser_action a;
			a.action_idx = 24;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<"] = a;
		}
		{
			parser_action a;
			a.action_idx = 24;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<="] = a;
		}
		{
			parser_action a;
			a.action_idx = 24;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<>"] = a;
		}
		{
			parser_action a;
			a.action_idx = 24;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["="] = a;
		}
		{
			parser_action a;
			a.action_idx = 24;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[">"] = a;
		}
		{
			parser_action a;
			a.action_idx = 24;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[">="] = a;
		}
		{
			parser_action a;
			a.action_idx = 24;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["AND"] = a;
		}
		{
			parser_action a;
			a.action_idx = 24;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["IN"] = a;
		}
		{
			parser_action a;
			a.action_idx = 24;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["LIKE"] = a;
		}
		{
			parser_action a;
			a.action_idx = 24;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["OR"] = a;
		}
		states[19] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 39;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions[")"] = a;
		}
		states[20] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 40;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions[","] = a;
		}
		{
			parser_action a;
			a.action_idx = 35;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[")"] = a;
		}
		states[21] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 4;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["EOF"] = a;
		}
		{
			parser_action a;
			a.action_idx = 4;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[")"] = a;
		}
		{
			parser_action a;
			a.action_idx = 4;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[","] = a;
		}
		{
			parser_action a;
			a.action_idx = 4;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["AND"] = a;
		}
		{
			parser_action a;
			a.action_idx = 4;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["OR"] = a;
		}
		states[22] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 1;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["-"] = a;
		}
		{
			parser_action a;
			a.action_idx = 2;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["("] = a;
		}
		{
			parser_action a;
			a.action_idx = 3;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["BoolLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 4;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["Id"] = a;
		}
		{
			parser_action a;
			a.action_idx = 5;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["IntegerLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 7;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["NULL"] = a;
		}
		{
			parser_action a;
			a.action_idx = 8;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["RealLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 9;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["StringLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 41;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Mult Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 14;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Negate Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 17;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Tuple"] = a;
		}
		{
			parser_action a;
			a.action_idx = 42;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Value"] = a;
		}
		states[23] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 1;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["-"] = a;
		}
		{
			parser_action a;
			a.action_idx = 2;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["("] = a;
		}
		{
			parser_action a;
			a.action_idx = 3;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["BoolLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 4;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["Id"] = a;
		}
		{
			parser_action a;
			a.action_idx = 5;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["IntegerLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 7;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["NULL"] = a;
		}
		{
			parser_action a;
			a.action_idx = 8;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["RealLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 9;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["StringLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 43;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Add Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 13;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Mult Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 14;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Negate Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 17;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Tuple"] = a;
		}
		{
			parser_action a;
			a.action_idx = 42;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Value"] = a;
		}
		states[24] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 1;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["-"] = a;
		}
		{
			parser_action a;
			a.action_idx = 2;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["("] = a;
		}
		{
			parser_action a;
			a.action_idx = 3;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["BoolLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 4;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["Id"] = a;
		}
		{
			parser_action a;
			a.action_idx = 5;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["IntegerLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 7;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["NULL"] = a;
		}
		{
			parser_action a;
			a.action_idx = 8;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["RealLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 9;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["StringLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 44;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Mult Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 14;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Negate Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 17;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Tuple"] = a;
		}
		{
			parser_action a;
			a.action_idx = 42;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Value"] = a;
		}
		states[25] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 1;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["-"] = a;
		}
		{
			parser_action a;
			a.action_idx = 2;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["("] = a;
		}
		{
			parser_action a;
			a.action_idx = 3;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["BoolLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 4;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["Id"] = a;
		}
		{
			parser_action a;
			a.action_idx = 5;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["IntegerLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 7;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["NULL"] = a;
		}
		{
			parser_action a;
			a.action_idx = 8;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["RealLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 9;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["StringLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 45;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Add Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 13;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Mult Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 14;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Negate Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 17;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Tuple"] = a;
		}
		{
			parser_action a;
			a.action_idx = 42;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Value"] = a;
		}
		states[26] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 1;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["-"] = a;
		}
		{
			parser_action a;
			a.action_idx = 2;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["("] = a;
		}
		{
			parser_action a;
			a.action_idx = 3;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["BoolLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 4;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["Id"] = a;
		}
		{
			parser_action a;
			a.action_idx = 5;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["IntegerLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 7;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["NULL"] = a;
		}
		{
			parser_action a;
			a.action_idx = 8;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["RealLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 9;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["StringLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 46;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Add Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 13;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Mult Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 14;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Negate Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 17;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Tuple"] = a;
		}
		{
			parser_action a;
			a.action_idx = 42;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Value"] = a;
		}
		states[27] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 1;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["-"] = a;
		}
		{
			parser_action a;
			a.action_idx = 2;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["("] = a;
		}
		{
			parser_action a;
			a.action_idx = 3;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["BoolLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 4;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["Id"] = a;
		}
		{
			parser_action a;
			a.action_idx = 5;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["IntegerLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 7;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["NULL"] = a;
		}
		{
			parser_action a;
			a.action_idx = 8;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["RealLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 9;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["StringLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 47;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Add Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 13;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Mult Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 14;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Negate Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 17;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Tuple"] = a;
		}
		{
			parser_action a;
			a.action_idx = 42;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Value"] = a;
		}
		states[28] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 1;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["-"] = a;
		}
		{
			parser_action a;
			a.action_idx = 2;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["("] = a;
		}
		{
			parser_action a;
			a.action_idx = 3;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["BoolLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 4;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["Id"] = a;
		}
		{
			parser_action a;
			a.action_idx = 5;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["IntegerLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 7;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["NULL"] = a;
		}
		{
			parser_action a;
			a.action_idx = 8;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["RealLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 9;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["StringLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 48;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Add Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 13;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Mult Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 14;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Negate Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 17;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Tuple"] = a;
		}
		{
			parser_action a;
			a.action_idx = 42;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Value"] = a;
		}
		states[29] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 1;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["-"] = a;
		}
		{
			parser_action a;
			a.action_idx = 2;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["("] = a;
		}
		{
			parser_action a;
			a.action_idx = 3;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["BoolLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 4;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["Id"] = a;
		}
		{
			parser_action a;
			a.action_idx = 5;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["IntegerLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 7;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["NULL"] = a;
		}
		{
			parser_action a;
			a.action_idx = 8;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["RealLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 9;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["StringLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 49;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Add Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 13;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Mult Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 14;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Negate Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 17;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Tuple"] = a;
		}
		{
			parser_action a;
			a.action_idx = 42;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Value"] = a;
		}
		states[30] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 1;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["-"] = a;
		}
		{
			parser_action a;
			a.action_idx = 2;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["("] = a;
		}
		{
			parser_action a;
			a.action_idx = 3;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["BoolLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 4;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["Id"] = a;
		}
		{
			parser_action a;
			a.action_idx = 5;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["IntegerLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 7;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["NULL"] = a;
		}
		{
			parser_action a;
			a.action_idx = 8;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["RealLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 9;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["StringLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 50;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Add Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 13;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Mult Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 14;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Negate Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 17;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Tuple"] = a;
		}
		{
			parser_action a;
			a.action_idx = 42;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Value"] = a;
		}
		states[31] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 2;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["("] = a;
		}
		{
			parser_action a;
			a.action_idx = 51;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Tuple"] = a;
		}
		states[32] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 52;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["StringLiteral"] = a;
		}
		states[33] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 1;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["-"] = a;
		}
		{
			parser_action a;
			a.action_idx = 2;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["("] = a;
		}
		{
			parser_action a;
			a.action_idx = 3;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["BoolLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 4;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["Id"] = a;
		}
		{
			parser_action a;
			a.action_idx = 5;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["IntegerLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 6;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["NOT"] = a;
		}
		{
			parser_action a;
			a.action_idx = 7;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["NULL"] = a;
		}
		{
			parser_action a;
			a.action_idx = 8;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["RealLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 9;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["StringLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 10;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Add Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 11;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["And Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 53;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Expression"] = a;
		}
		{
			parser_action a;
			a.action_idx = 13;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Mult Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 14;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Negate Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 15;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Not Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 16;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Pred Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 17;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Tuple"] = a;
		}
		{
			parser_action a;
			a.action_idx = 18;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Value"] = a;
		}
		states[34] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 1;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["-"] = a;
		}
		{
			parser_action a;
			a.action_idx = 2;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["("] = a;
		}
		{
			parser_action a;
			a.action_idx = 3;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["BoolLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 4;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["Id"] = a;
		}
		{
			parser_action a;
			a.action_idx = 5;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["IntegerLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 7;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["NULL"] = a;
		}
		{
			parser_action a;
			a.action_idx = 8;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["RealLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 9;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["StringLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 54;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Negate Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 17;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Tuple"] = a;
		}
		{
			parser_action a;
			a.action_idx = 42;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Value"] = a;
		}
		states[35] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 1;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["-"] = a;
		}
		{
			parser_action a;
			a.action_idx = 2;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["("] = a;
		}
		{
			parser_action a;
			a.action_idx = 3;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["BoolLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 4;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["Id"] = a;
		}
		{
			parser_action a;
			a.action_idx = 5;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["IntegerLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 7;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["NULL"] = a;
		}
		{
			parser_action a;
			a.action_idx = 8;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["RealLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 9;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["StringLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 55;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Negate Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 17;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Tuple"] = a;
		}
		{
			parser_action a;
			a.action_idx = 42;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Value"] = a;
		}
		states[36] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 1;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["-"] = a;
		}
		{
			parser_action a;
			a.action_idx = 2;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["("] = a;
		}
		{
			parser_action a;
			a.action_idx = 3;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["BoolLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 4;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["Id"] = a;
		}
		{
			parser_action a;
			a.action_idx = 5;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["IntegerLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 6;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["NOT"] = a;
		}
		{
			parser_action a;
			a.action_idx = 7;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["NULL"] = a;
		}
		{
			parser_action a;
			a.action_idx = 8;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["RealLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 9;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["StringLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 10;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Add Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 56;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["And Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 13;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Mult Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 14;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Negate Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 15;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Not Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 16;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Pred Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 17;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Tuple"] = a;
		}
		{
			parser_action a;
			a.action_idx = 18;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Value"] = a;
		}
		states[37] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 57;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["NOT"] = a;
		}
		{
			parser_action a;
			a.action_idx = 58;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["NULL"] = a;
		}
		states[38] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 33;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["EOF"] = a;
		}
		{
			parser_action a;
			a.action_idx = 33;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["-"] = a;
		}
		{
			parser_action a;
			a.action_idx = 33;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["!="] = a;
		}
		{
			parser_action a;
			a.action_idx = 33;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[")"] = a;
		}
		{
			parser_action a;
			a.action_idx = 33;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["*"] = a;
		}
		{
			parser_action a;
			a.action_idx = 33;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[","] = a;
		}
		{
			parser_action a;
			a.action_idx = 33;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["/"] = a;
		}
		{
			parser_action a;
			a.action_idx = 33;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["+"] = a;
		}
		{
			parser_action a;
			a.action_idx = 33;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<"] = a;
		}
		{
			parser_action a;
			a.action_idx = 33;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<="] = a;
		}
		{
			parser_action a;
			a.action_idx = 33;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<>"] = a;
		}
		{
			parser_action a;
			a.action_idx = 33;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["="] = a;
		}
		{
			parser_action a;
			a.action_idx = 33;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[">"] = a;
		}
		{
			parser_action a;
			a.action_idx = 33;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[">="] = a;
		}
		{
			parser_action a;
			a.action_idx = 33;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["AND"] = a;
		}
		{
			parser_action a;
			a.action_idx = 33;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["IN"] = a;
		}
		{
			parser_action a;
			a.action_idx = 33;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["IS"] = a;
		}
		{
			parser_action a;
			a.action_idx = 33;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["LIKE"] = a;
		}
		{
			parser_action a;
			a.action_idx = 33;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["OR"] = a;
		}
		states[39] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 1;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["-"] = a;
		}
		{
			parser_action a;
			a.action_idx = 2;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["("] = a;
		}
		{
			parser_action a;
			a.action_idx = 3;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["BoolLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 4;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["Id"] = a;
		}
		{
			parser_action a;
			a.action_idx = 5;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["IntegerLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 6;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["NOT"] = a;
		}
		{
			parser_action a;
			a.action_idx = 7;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["NULL"] = a;
		}
		{
			parser_action a;
			a.action_idx = 8;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["RealLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 9;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["StringLiteral"] = a;
		}
		{
			parser_action a;
			a.action_idx = 10;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Add Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 11;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["And Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 59;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Expr List"] = a;
		}
		{
			parser_action a;
			a.action_idx = 21;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Expression"] = a;
		}
		{
			parser_action a;
			a.action_idx = 13;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Mult Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 14;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Negate Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 15;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Not Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 16;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Pred Exp"] = a;
		}
		{
			parser_action a;
			a.action_idx = 17;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Tuple"] = a;
		}
		{
			parser_action a;
			a.action_idx = 18;
			a.action = parser_action::SHIFT_REDUCE::GOTO_STATE;
			st.actions["Value"] = a;
		}
		states[40] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 35;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["*"] = a;
		}
		{
			parser_action a;
			a.action_idx = 36;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["/"] = a;
		}
		{
			parser_action a;
			a.action_idx = 19;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["EOF"] = a;
		}
		{
			parser_action a;
			a.action_idx = 19;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["-"] = a;
		}
		{
			parser_action a;
			a.action_idx = 19;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["!="] = a;
		}
		{
			parser_action a;
			a.action_idx = 19;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[")"] = a;
		}
		{
			parser_action a;
			a.action_idx = 19;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[","] = a;
		}
		{
			parser_action a;
			a.action_idx = 19;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["+"] = a;
		}
		{
			parser_action a;
			a.action_idx = 19;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<"] = a;
		}
		{
			parser_action a;
			a.action_idx = 19;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<="] = a;
		}
		{
			parser_action a;
			a.action_idx = 19;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<>"] = a;
		}
		{
			parser_action a;
			a.action_idx = 19;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["="] = a;
		}
		{
			parser_action a;
			a.action_idx = 19;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[">"] = a;
		}
		{
			parser_action a;
			a.action_idx = 19;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[">="] = a;
		}
		{
			parser_action a;
			a.action_idx = 19;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["AND"] = a;
		}
		{
			parser_action a;
			a.action_idx = 19;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["IN"] = a;
		}
		{
			parser_action a;
			a.action_idx = 19;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["LIKE"] = a;
		}
		{
			parser_action a;
			a.action_idx = 19;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["OR"] = a;
		}
		states[41] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 25;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["EOF"] = a;
		}
		{
			parser_action a;
			a.action_idx = 25;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["-"] = a;
		}
		{
			parser_action a;
			a.action_idx = 25;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["!="] = a;
		}
		{
			parser_action a;
			a.action_idx = 25;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[")"] = a;
		}
		{
			parser_action a;
			a.action_idx = 25;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["*"] = a;
		}
		{
			parser_action a;
			a.action_idx = 25;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[","] = a;
		}
		{
			parser_action a;
			a.action_idx = 25;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["/"] = a;
		}
		{
			parser_action a;
			a.action_idx = 25;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["+"] = a;
		}
		{
			parser_action a;
			a.action_idx = 25;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<"] = a;
		}
		{
			parser_action a;
			a.action_idx = 25;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<="] = a;
		}
		{
			parser_action a;
			a.action_idx = 25;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<>"] = a;
		}
		{
			parser_action a;
			a.action_idx = 25;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["="] = a;
		}
		{
			parser_action a;
			a.action_idx = 25;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[">"] = a;
		}
		{
			parser_action a;
			a.action_idx = 25;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[">="] = a;
		}
		{
			parser_action a;
			a.action_idx = 25;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["AND"] = a;
		}
		{
			parser_action a;
			a.action_idx = 25;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["IN"] = a;
		}
		{
			parser_action a;
			a.action_idx = 25;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["LIKE"] = a;
		}
		{
			parser_action a;
			a.action_idx = 25;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["OR"] = a;
		}
		states[42] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 23;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["-"] = a;
		}
		{
			parser_action a;
			a.action_idx = 25;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["+"] = a;
		}
		{
			parser_action a;
			a.action_idx = 12;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["EOF"] = a;
		}
		{
			parser_action a;
			a.action_idx = 12;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[")"] = a;
		}
		{
			parser_action a;
			a.action_idx = 12;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[","] = a;
		}
		{
			parser_action a;
			a.action_idx = 12;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["AND"] = a;
		}
		{
			parser_action a;
			a.action_idx = 12;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["OR"] = a;
		}
		states[43] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 35;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["*"] = a;
		}
		{
			parser_action a;
			a.action_idx = 36;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["/"] = a;
		}
		{
			parser_action a;
			a.action_idx = 18;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["EOF"] = a;
		}
		{
			parser_action a;
			a.action_idx = 18;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["-"] = a;
		}
		{
			parser_action a;
			a.action_idx = 18;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["!="] = a;
		}
		{
			parser_action a;
			a.action_idx = 18;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[")"] = a;
		}
		{
			parser_action a;
			a.action_idx = 18;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[","] = a;
		}
		{
			parser_action a;
			a.action_idx = 18;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["+"] = a;
		}
		{
			parser_action a;
			a.action_idx = 18;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<"] = a;
		}
		{
			parser_action a;
			a.action_idx = 18;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<="] = a;
		}
		{
			parser_action a;
			a.action_idx = 18;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<>"] = a;
		}
		{
			parser_action a;
			a.action_idx = 18;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["="] = a;
		}
		{
			parser_action a;
			a.action_idx = 18;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[">"] = a;
		}
		{
			parser_action a;
			a.action_idx = 18;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[">="] = a;
		}
		{
			parser_action a;
			a.action_idx = 18;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["AND"] = a;
		}
		{
			parser_action a;
			a.action_idx = 18;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["IN"] = a;
		}
		{
			parser_action a;
			a.action_idx = 18;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["LIKE"] = a;
		}
		{
			parser_action a;
			a.action_idx = 18;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["OR"] = a;
		}
		states[44] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 23;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["-"] = a;
		}
		{
			parser_action a;
			a.action_idx = 25;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["+"] = a;
		}
		{
			parser_action a;
			a.action_idx = 15;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["EOF"] = a;
		}
		{
			parser_action a;
			a.action_idx = 15;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[")"] = a;
		}
		{
			parser_action a;
			a.action_idx = 15;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[","] = a;
		}
		{
			parser_action a;
			a.action_idx = 15;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["AND"] = a;
		}
		{
			parser_action a;
			a.action_idx = 15;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["OR"] = a;
		}
		states[45] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 23;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["-"] = a;
		}
		{
			parser_action a;
			a.action_idx = 25;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["+"] = a;
		}
		{
			parser_action a;
			a.action_idx = 16;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["EOF"] = a;
		}
		{
			parser_action a;
			a.action_idx = 16;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[")"] = a;
		}
		{
			parser_action a;
			a.action_idx = 16;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[","] = a;
		}
		{
			parser_action a;
			a.action_idx = 16;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["AND"] = a;
		}
		{
			parser_action a;
			a.action_idx = 16;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["OR"] = a;
		}
		states[46] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 23;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["-"] = a;
		}
		{
			parser_action a;
			a.action_idx = 25;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["+"] = a;
		}
		{
			parser_action a;
			a.action_idx = 11;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["EOF"] = a;
		}
		{
			parser_action a;
			a.action_idx = 11;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[")"] = a;
		}
		{
			parser_action a;
			a.action_idx = 11;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[","] = a;
		}
		{
			parser_action a;
			a.action_idx = 11;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["AND"] = a;
		}
		{
			parser_action a;
			a.action_idx = 11;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["OR"] = a;
		}
		states[47] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 23;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["-"] = a;
		}
		{
			parser_action a;
			a.action_idx = 25;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["+"] = a;
		}
		{
			parser_action a;
			a.action_idx = 10;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["EOF"] = a;
		}
		{
			parser_action a;
			a.action_idx = 10;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[")"] = a;
		}
		{
			parser_action a;
			a.action_idx = 10;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[","] = a;
		}
		{
			parser_action a;
			a.action_idx = 10;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["AND"] = a;
		}
		{
			parser_action a;
			a.action_idx = 10;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["OR"] = a;
		}
		states[48] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 23;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["-"] = a;
		}
		{
			parser_action a;
			a.action_idx = 25;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["+"] = a;
		}
		{
			parser_action a;
			a.action_idx = 13;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["EOF"] = a;
		}
		{
			parser_action a;
			a.action_idx = 13;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[")"] = a;
		}
		{
			parser_action a;
			a.action_idx = 13;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[","] = a;
		}
		{
			parser_action a;
			a.action_idx = 13;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["AND"] = a;
		}
		{
			parser_action a;
			a.action_idx = 13;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["OR"] = a;
		}
		states[49] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 23;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["-"] = a;
		}
		{
			parser_action a;
			a.action_idx = 25;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["+"] = a;
		}
		{
			parser_action a;
			a.action_idx = 14;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["EOF"] = a;
		}
		{
			parser_action a;
			a.action_idx = 14;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[")"] = a;
		}
		{
			parser_action a;
			a.action_idx = 14;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[","] = a;
		}
		{
			parser_action a;
			a.action_idx = 14;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["AND"] = a;
		}
		{
			parser_action a;
			a.action_idx = 14;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["OR"] = a;
		}
		states[50] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 9;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["EOF"] = a;
		}
		{
			parser_action a;
			a.action_idx = 9;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[")"] = a;
		}
		{
			parser_action a;
			a.action_idx = 9;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[","] = a;
		}
		{
			parser_action a;
			a.action_idx = 9;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["AND"] = a;
		}
		{
			parser_action a;
			a.action_idx = 9;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["OR"] = a;
		}
		states[51] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 8;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["EOF"] = a;
		}
		{
			parser_action a;
			a.action_idx = 8;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[")"] = a;
		}
		{
			parser_action a;
			a.action_idx = 8;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[","] = a;
		}
		{
			parser_action a;
			a.action_idx = 8;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["AND"] = a;
		}
		{
			parser_action a;
			a.action_idx = 8;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["OR"] = a;
		}
		states[52] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 0;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["EOF"] = a;
		}
		{
			parser_action a;
			a.action_idx = 0;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[")"] = a;
		}
		{
			parser_action a;
			a.action_idx = 0;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[","] = a;
		}
		states[53] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 21;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["EOF"] = a;
		}
		{
			parser_action a;
			a.action_idx = 21;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["-"] = a;
		}
		{
			parser_action a;
			a.action_idx = 21;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["!="] = a;
		}
		{
			parser_action a;
			a.action_idx = 21;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[")"] = a;
		}
		{
			parser_action a;
			a.action_idx = 21;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["*"] = a;
		}
		{
			parser_action a;
			a.action_idx = 21;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[","] = a;
		}
		{
			parser_action a;
			a.action_idx = 21;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["/"] = a;
		}
		{
			parser_action a;
			a.action_idx = 21;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["+"] = a;
		}
		{
			parser_action a;
			a.action_idx = 21;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<"] = a;
		}
		{
			parser_action a;
			a.action_idx = 21;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<="] = a;
		}
		{
			parser_action a;
			a.action_idx = 21;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<>"] = a;
		}
		{
			parser_action a;
			a.action_idx = 21;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["="] = a;
		}
		{
			parser_action a;
			a.action_idx = 21;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[">"] = a;
		}
		{
			parser_action a;
			a.action_idx = 21;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[">="] = a;
		}
		{
			parser_action a;
			a.action_idx = 21;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["AND"] = a;
		}
		{
			parser_action a;
			a.action_idx = 21;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["IN"] = a;
		}
		{
			parser_action a;
			a.action_idx = 21;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["LIKE"] = a;
		}
		{
			parser_action a;
			a.action_idx = 21;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["OR"] = a;
		}
		states[54] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 22;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["EOF"] = a;
		}
		{
			parser_action a;
			a.action_idx = 22;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["-"] = a;
		}
		{
			parser_action a;
			a.action_idx = 22;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["!="] = a;
		}
		{
			parser_action a;
			a.action_idx = 22;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[")"] = a;
		}
		{
			parser_action a;
			a.action_idx = 22;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["*"] = a;
		}
		{
			parser_action a;
			a.action_idx = 22;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[","] = a;
		}
		{
			parser_action a;
			a.action_idx = 22;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["/"] = a;
		}
		{
			parser_action a;
			a.action_idx = 22;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["+"] = a;
		}
		{
			parser_action a;
			a.action_idx = 22;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<"] = a;
		}
		{
			parser_action a;
			a.action_idx = 22;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<="] = a;
		}
		{
			parser_action a;
			a.action_idx = 22;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["<>"] = a;
		}
		{
			parser_action a;
			a.action_idx = 22;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["="] = a;
		}
		{
			parser_action a;
			a.action_idx = 22;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[">"] = a;
		}
		{
			parser_action a;
			a.action_idx = 22;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[">="] = a;
		}
		{
			parser_action a;
			a.action_idx = 22;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["AND"] = a;
		}
		{
			parser_action a;
			a.action_idx = 22;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["IN"] = a;
		}
		{
			parser_action a;
			a.action_idx = 22;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["LIKE"] = a;
		}
		{
			parser_action a;
			a.action_idx = 22;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["OR"] = a;
		}
		states[55] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 2;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["EOF"] = a;
		}
		{
			parser_action a;
			a.action_idx = 2;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[")"] = a;
		}
		{
			parser_action a;
			a.action_idx = 2;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[","] = a;
		}
		{
			parser_action a;
			a.action_idx = 2;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["OR"] = a;
		}
		states[56] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 60;
			a.action = parser_action::SHIFT_REDUCE::SHIFT;
			st.actions["NULL"] = a;
		}
		states[57] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 7;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["EOF"] = a;
		}
		{
			parser_action a;
			a.action_idx = 7;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[")"] = a;
		}
		{
			parser_action a;
			a.action_idx = 7;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[","] = a;
		}
		{
			parser_action a;
			a.action_idx = 7;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["AND"] = a;
		}
		{
			parser_action a;
			a.action_idx = 7;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["OR"] = a;
		}
		states[58] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 34;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[")"] = a;
		}
		states[59] = st;
	}

	{
		parser_state st;
		{
			parser_action a;
			a.action_idx = 6;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["EOF"] = a;
		}
		{
			parser_action a;
			a.action_idx = 6;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[")"] = a;
		}
		{
			parser_action a;
			a.action_idx = 6;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions[","] = a;
		}
		{
			parser_action a;
			a.action_idx = 6;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["AND"] = a;
		}
		{
			parser_action a;
			a.action_idx = 6;
			a.action = parser_action::SHIFT_REDUCE::REDUCE;
			st.actions["OR"] = a;
		}
		states[60] = st;
	}

	return states;
}