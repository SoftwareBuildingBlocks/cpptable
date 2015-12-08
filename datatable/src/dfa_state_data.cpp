#include "dfa_state_data.h"
#include "string_util.h"

std::set<std::string> dfa_state_data::get_terminal_tokens()
{
	std::set<std::string> tmp;
	tmp.insert("-");
	tmp.insert("!=");
	tmp.insert("(");
	tmp.insert(")");
	tmp.insert("*");
	tmp.insert(",");
	tmp.insert("/");
	tmp.insert("+");
	tmp.insert("<");
	tmp.insert("<=");
	tmp.insert("<>");
	tmp.insert("=");
	tmp.insert(">");
	tmp.insert(">=");
	tmp.insert("AND");
	tmp.insert("BoolLiteral");
	tmp.insert("Id");
	tmp.insert("IN");
	tmp.insert("IntegerLiteral");
	tmp.insert("IS");
	tmp.insert("LIKE");
	tmp.insert("NOT");
	tmp.insert("NULL");
	tmp.insert("OR");
	tmp.insert("RealLiteral");
	tmp.insert("StringLiteral");
	return tmp;
}

using tst = tokenizer_state_transition;

template <unsigned int i>
tokenizer_state get_tok_state()
{
	throw std::runtime_error(format<128>("Unimplemented state %d", i));
}

template<>
tokenizer_state get_tok_state<0>()
{

	tokenizer_state st;
	st.transitions.push_back(tst(1, "\x09\x0A\x0B\x0C\x0D\x20\x85\xA0"));
	st.transitions.push_back(tst(2, "-"));
	st.transitions.push_back(tst(3, "!"));
	st.transitions.push_back(tst(5, "("));
	st.transitions.push_back(tst(6, ")"));
	st.transitions.push_back(tst(7, "*"));
	st.transitions.push_back(tst(8, ","));
	st.transitions.push_back(tst(9, "/"));
	st.transitions.push_back(tst(10, "+"));
	st.transitions.push_back(tst(11, "="));
	st.transitions.push_back(tst(12, "BCDEGHJKMPQRSUVWXYZbcdeghjkmpqrsuvwxyz"));
	st.transitions.push_back(tst(20, "["));
	st.transitions.push_back(tst(23, "\""));
	st.transitions.push_back(tst(26, "'"));
	st.transitions.push_back(tst(29, "0123456789"));
	st.transitions.push_back(tst(32, "<"));
	st.transitions.push_back(tst(35, ">"));
	st.transitions.push_back(tst(37, "Aa"));
	st.transitions.push_back(tst(40, "Ff"));
	st.transitions.push_back(tst(45, "Ii"));
	st.transitions.push_back(tst(48, "Ll"));
	st.transitions.push_back(tst(52, "Nn"));
	st.transitions.push_back(tst(58, "Oo"));
	st.transitions.push_back(tst(60, "Tt"));


	return st;
}

template<>
tokenizer_state get_tok_state<1>()
{

	tokenizer_state st;
	st.transitions.push_back(tst(1, "\x09\x0A\x0B\x0C\x0D\x20\x85\xA0"));

	st.accepted_token = "Whitespace";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<2>()
{

	tokenizer_state st;

	st.accepted_token = "-";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<3>()
{

	tokenizer_state st;
	st.transitions.push_back(tst(4, "="));


	return st;
}

template<>
tokenizer_state get_tok_state<4>()
{

	tokenizer_state st;

	st.accepted_token = "!=";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<5>()
{

	tokenizer_state st;

	st.accepted_token = "(";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<6>()
{

	tokenizer_state st;

	st.accepted_token = ")";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<7>()
{

	tokenizer_state st;

	st.accepted_token = "*";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<8>()
{

	tokenizer_state st;

	st.accepted_token = ",";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<9>()
{

	tokenizer_state st;

	st.accepted_token = "/";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<10>()
{

	tokenizer_state st;

	st.accepted_token = "+";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<11>()
{

	tokenizer_state st;

	st.accepted_token = "=";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<12>()
{

	tokenizer_state st;
	st.transitions.push_back(tst(13, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz"));
	st.transitions.push_back(tst(14, "."));

	st.accepted_token = "Id";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<13>()
{

	tokenizer_state st;
	st.transitions.push_back(tst(13, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz"));
	st.transitions.push_back(tst(14, "."));

	st.accepted_token = "Id";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<14>()
{

	tokenizer_state st;
	st.transitions.push_back(tst(15, "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"));
	st.transitions.push_back(tst(17, "["));


	return st;
}

template<>
tokenizer_state get_tok_state<15>()
{

	tokenizer_state st;
	st.transitions.push_back(tst(16, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz"));

	st.accepted_token = "Id";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<16>()
{

	tokenizer_state st;
	st.transitions.push_back(tst(16, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz"));

	st.accepted_token = "Id";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<17>()
{

	tokenizer_state st;
	st.transitions.push_back(tst(18, " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ\\^_`abcdefghijklmnopqrstuvwxyz{|}~ "));


	return st;
}

template<>
tokenizer_state get_tok_state<18>()
{

	tokenizer_state st;
	st.transitions.push_back(tst(18, " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ\\^_`abcdefghijklmnopqrstuvwxyz{|}~ "));
	st.transitions.push_back(tst(19, "]"));


	return st;
}

template<>
tokenizer_state get_tok_state<19>()
{

	tokenizer_state st;

	st.accepted_token = "Id";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<20>()
{

	tokenizer_state st;
	st.transitions.push_back(tst(21, " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ\\^_`abcdefghijklmnopqrstuvwxyz{|}~ "));


	return st;
}

template<>
tokenizer_state get_tok_state<21>()
{

	tokenizer_state st;
	st.transitions.push_back(tst(21, " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ\\^_`abcdefghijklmnopqrstuvwxyz{|}~ "));
	st.transitions.push_back(tst(22, "]"));


	return st;
}

template<>
tokenizer_state get_tok_state<22>()
{

	tokenizer_state st;
	st.transitions.push_back(tst(14, "."));

	st.accepted_token = "Id";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<23>()
{

	tokenizer_state st;
	st.transitions.push_back(tst(24, " !#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~ "));
	st.transitions.push_back(tst(25, "\""));


	return st;
}

template<>
tokenizer_state get_tok_state<24>()
{

	tokenizer_state st;
	st.transitions.push_back(tst(24, " !#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~ "));
	st.transitions.push_back(tst(25, "\""));


	return st;
}

template<>
tokenizer_state get_tok_state<25>()
{

	tokenizer_state st;

	st.accepted_token = "StringLiteral";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<26>()
{

	tokenizer_state st;
	st.transitions.push_back(tst(27, " !\"#$%&()*+, -. / 0123456789:; <= > ? @ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~"));
	st.transitions.push_back(tst(28, "'"));


	return st;
}

template<>
tokenizer_state get_tok_state<27>()
{

	tokenizer_state st;
	st.transitions.push_back(tst(27, " !\"#$%&()*+, -. / 0123456789:; <= > ? @ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~"));
	st.transitions.push_back(tst(28, "'"));


	return st;
}

template<>
tokenizer_state get_tok_state<28>()
{

	tokenizer_state st;

	st.accepted_token = "StringLiteral";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<29>()
{

	tokenizer_state st;
	st.transitions.push_back(tst(30, "."));
	st.transitions.push_back(tst(29, "0123456789"));

	st.accepted_token = "IntegerLiteral";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<30>()
{

	tokenizer_state st;
	st.transitions.push_back(tst(31, "0123456789"));


	return st;
}

template<>
tokenizer_state get_tok_state<31>()
{

	tokenizer_state st;
	st.transitions.push_back(tst(31, "0123456789"));

	st.accepted_token = "RealLiteral";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<32>()
{

	tokenizer_state st;
	st.transitions.push_back(tst(33, "="));
	st.transitions.push_back(tst(34, ">"));

	st.accepted_token = "<";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<33>()
{

	tokenizer_state st;

	st.accepted_token = "<=";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<34>()
{

	tokenizer_state st;

	st.accepted_token = "<>";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<35>()
{

	tokenizer_state st;
	st.transitions.push_back(tst(36, "="));

	st.accepted_token = ">";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<36>()
{

	tokenizer_state st;

	st.accepted_token = ">=";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<37>()
{

	tokenizer_state st;
	st.transitions.push_back(tst(13, "0123456789ABCDEFGHIJKLMOPQRSTUVWXYZ_abcdefghijklmopqrstuvwxyz"));
	st.transitions.push_back(tst(14, "."));
	st.transitions.push_back(tst(38, "Nn"));

	st.accepted_token = "Id";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<38>()
{

	tokenizer_state st;
	st.transitions.push_back(tst(13, "0123456789ABCEFGHIJKLMNOPQRSTUVWXYZ_abcefghijklmnopqrstuvwxyz"));
	st.transitions.push_back(tst(14, "."));
	st.transitions.push_back(tst(39, "Dd"));

	st.accepted_token = "Id";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<39>()
{

	tokenizer_state st;
	st.transitions.push_back(tst(13, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz"));
	st.transitions.push_back(tst(14, "."));

	st.accepted_token = "AND";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<40>()
{

	tokenizer_state st;
	st.transitions.push_back(tst(13, "0123456789BCDEFGHIJKLMNOPQRSTUVWXYZ_bcdefghijklmnopqrstuvwxyz"));
	st.transitions.push_back(tst(14, "."));
	st.transitions.push_back(tst(41, "Aa"));

	st.accepted_token = "Id";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<41>()
{

	tokenizer_state st;
	st.transitions.push_back(tst(13, "0123456789ABCDEFGHIJKMNOPQRSTUVWXYZ_abcdefghijkmnopqrstuvwxyz"));
	st.transitions.push_back(tst(14, "."));
	st.transitions.push_back(tst(42, "Ll"));

	st.accepted_token = "Id";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<42>()
{

	tokenizer_state st;
	st.transitions.push_back(tst(13, "0123456789ABCDEFGHIJKLMNOPQRTUVWXYZ_abcdefghijklmnopqrtuvwxyz"));
	st.transitions.push_back(tst(14, "."));
	st.transitions.push_back(tst(43, "Ss"));

	st.accepted_token = "Id";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<43>()
{

	tokenizer_state st;
	st.transitions.push_back(tst(13, "0123456789ABCDFGHIJKLMNOPQRSTUVWXYZ_abcdfghijklmnopqrstuvwxyz"));
	st.transitions.push_back(tst(14, "."));
	st.transitions.push_back(tst(44, "Ee"));

	st.accepted_token = "Id";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<44>()
{

	tokenizer_state st;
	st.transitions.push_back(tst(13, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz"));
	st.transitions.push_back(tst(14, "."));

	st.accepted_token = "BoolLiteral";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<45>()
{

	tokenizer_state st;
	st.transitions.push_back(tst(13, "0123456789ABCDEFGHIJKLMOPQRTUVWXYZ_abcdefghijklmopqrtuvwxyz"));
	st.transitions.push_back(tst(14, "."));
	st.transitions.push_back(tst(46, "Nn"));
	st.transitions.push_back(tst(47, "Ss"));

	st.accepted_token = "Id";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<46>()
{

	tokenizer_state st;
	st.transitions.push_back(tst(13, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz"));
	st.transitions.push_back(tst(14, "."));

	st.accepted_token = "IN";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<47>()
{

	tokenizer_state st;
	st.transitions.push_back(tst(13, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz"));
	st.transitions.push_back(tst(14, "."));

	st.accepted_token = "IS";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<48>()
{

	tokenizer_state st;
	st.transitions.push_back(tst(13, "0123456789ABCDEFGHJKLMNOPQRSTUVWXYZ_abcdefghjklmnopqrstuvwxyz"));
	st.transitions.push_back(tst(14, "."));
	st.transitions.push_back(tst(49, "Ii"));

	st.accepted_token = "Id";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<49>()
{

	tokenizer_state st;
	st.transitions.push_back(tst(13, "0123456789ABCDEFGHIJLMNOPQRSTUVWXYZ_abcdefghijlmnopqrstuvwxyz"));
	st.transitions.push_back(tst(14, "."));
	st.transitions.push_back(tst(50, "Kk"));

	st.accepted_token = "Id";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<50>()
{

	tokenizer_state st;
	st.transitions.push_back(tst(13, "0123456789ABCDFGHIJKLMNOPQRSTUVWXYZ_abcdfghijklmnopqrstuvwxyz"));
	st.transitions.push_back(tst(14, "."));
	st.transitions.push_back(tst(51, "Ee"));

	st.accepted_token = "Id";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<51>()
{

	tokenizer_state st;
	st.transitions.push_back(tst(13, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz"));
	st.transitions.push_back(tst(14, "."));

	st.accepted_token = "LIKE";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<52>()
{

	tokenizer_state st;
	st.transitions.push_back(tst(13, "0123456789ABCDEFGHIJKLMNPQRSTVWXYZ_abcdefghijklmnpqrstvwxyz"));
	st.transitions.push_back(tst(14, "."));
	st.transitions.push_back(tst(53, "Oo"));
	st.transitions.push_back(tst(55, "Uu"));

	st.accepted_token = "Id";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<53>()
{

	tokenizer_state st;
	st.transitions.push_back(tst(13, "0123456789ABCDEFGHIJKLMNOPQRSUVWXYZ_abcdefghijklmnopqrsuvwxyz"));
	st.transitions.push_back(tst(14, "."));
	st.transitions.push_back(tst(54, "Tt"));

	st.accepted_token = "Id";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<54>()
{

	tokenizer_state st;
	st.transitions.push_back(tst(13, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz"));
	st.transitions.push_back(tst(14, "."));

	st.accepted_token = "NOT";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<55>()
{

	tokenizer_state st;
	st.transitions.push_back(tst(13, "0123456789ABCDEFGHIJKMNOPQRSTUVWXYZ_abcdefghijkmnopqrstuvwxyz"));
	st.transitions.push_back(tst(14, "."));
	st.transitions.push_back(tst(56, "Ll"));

	st.accepted_token = "Id";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<56>()
{

	tokenizer_state st;
	st.transitions.push_back(tst(13, "0123456789ABCDEFGHIJKMNOPQRSTUVWXYZ_abcdefghijkmnopqrstuvwxyz"));
	st.transitions.push_back(tst(14, "."));
	st.transitions.push_back(tst(57, "Ll"));

	st.accepted_token = "Id";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<57>()
{

	tokenizer_state st;
	st.transitions.push_back(tst(13, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz"));
	st.transitions.push_back(tst(14, "."));

	st.accepted_token = "NULL";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<58>()
{

	tokenizer_state st;
	st.transitions.push_back(tst(13, "0123456789ABCDEFGHIJKLMNOPQSTUVWXYZ_abcdefghijklmnopqstuvwxyz"));
	st.transitions.push_back(tst(14, "."));
	st.transitions.push_back(tst(59, "Rr"));

	st.accepted_token = "Id";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<59>()
{

	tokenizer_state st;
	st.transitions.push_back(tst(13, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz"));
	st.transitions.push_back(tst(14, "."));

	st.accepted_token = "OR";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<60>()
{

	tokenizer_state st;
	st.transitions.push_back(tst(13, "0123456789ABCDEFGHIJKLMNOPQSTUVWXYZ_abcdefghijklmnopqstuvwxyz"));
	st.transitions.push_back(tst(14, "."));
	st.transitions.push_back(tst(61, "Rr"));

	st.accepted_token = "Id";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<61>()
{

	tokenizer_state st;
	st.transitions.push_back(tst(13, "0123456789ABCDEFGHIJKLMNOPQRSTVWXYZ_abcdefghijklmnopqrstvwxyz"));
	st.transitions.push_back(tst(14, "."));
	st.transitions.push_back(tst(62, "Uu"));

	st.accepted_token = "Id";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<62>()
{

	tokenizer_state st;
	st.transitions.push_back(tst(13, "0123456789ABCDFGHIJKLMNOPQRSTUVWXYZ_abcdfghijklmnopqrstuvwxyz"));
	st.transitions.push_back(tst(14, "."));
	st.transitions.push_back(tst(63, "Ee"));

	st.accepted_token = "Id";
	st.is_accept_state = true;

	return st;
}

template<>
tokenizer_state get_tok_state<63>()
{

	tokenizer_state st;
	st.transitions.push_back(tst(13, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz"));
	st.transitions.push_back(tst(14, "."));

	st.accepted_token = "BoolLiteral";
	st.is_accept_state = true;
	return st;
}

template <int i>
void foo(std::vector<tokenizer_state>& in)
{
	in.push_back(get_tok_state<i>());
	foo<i + 1>(in);
}

template <>
void foo<64>(std::vector<tokenizer_state>& in)
{
}

std::vector<tokenizer_state> dfa_state_data::get_states()
{
	std::vector<tokenizer_state> tmp;
	foo<0>(tmp);
	return tmp;
}
