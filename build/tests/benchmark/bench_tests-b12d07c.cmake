add_test( B_calculate_thrust /afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/build/tests/benchmark/bench calculate_thrust  )
set_tests_properties( B_calculate_thrust PROPERTIES WORKING_DIRECTORY /afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/tests/benchmark)
add_test( B_isPV /afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/build/tests/benchmark/bench isPV  )
set_tests_properties( B_isPV PROPERTIES WORKING_DIRECTORY /afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/tests/benchmark)
set( bench_TESTS B_calculate_thrust B_isPV)
