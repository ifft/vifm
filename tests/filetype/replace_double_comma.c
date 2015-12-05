#include <stic.h>

#include <stdlib.h>

#include "../../src/filetype.h"

TEST(no_comma)
{
	char buf[] = "echo something";
	replace_double_comma(buf);
	assert_string_equal("echo something", buf);
}

TEST(one_command)
{
	char buf[] = "echo tpattern,,with,,comma";
	replace_double_comma(buf);
	assert_string_equal("echo tpattern,with,comma", buf);
}

TEST(many_commands)
{
	char buf[] = "echo first,,one,echo second,,one";
	replace_double_comma(buf);
	assert_string_equal("echo first,one,echo second,one", buf);
}

/* vim: set tabstop=2 softtabstop=2 shiftwidth=2 noexpandtab cinoptions-=(0 : */
/* vim: set cinoptions+=t0 filetype=c : */
