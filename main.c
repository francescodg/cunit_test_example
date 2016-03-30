#include "CUnit/Basic.h"

int init_suite_1()
{
	return 0;
}

int clean_suite_1()
{
	return 0;
}

void testSimple()
{
	CU_FAIL("Failed test");
}

/* The main() function for setting up and running the tests.
 * Returns a CUE_SUCCESS on successful running, another
 * CUnit error code on failure.
 */
int main()
{
	CU_pSuite pSuite1 = NULL;

	/* initialize the CUnit test registry */
	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error();

	/* add a suite to the registry */
	pSuite1 = CU_add_suite("Suite 1", init_suite_1, clean_suite_1);

	if (pSuite1 == NULL) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	/* Add the tests to suite 1 */ 
	if ((CU_add_test(pSuite1, "Simple test", testSimple) == NULL)) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	/* Run all tests using the CUnit Basic interface */

	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}
