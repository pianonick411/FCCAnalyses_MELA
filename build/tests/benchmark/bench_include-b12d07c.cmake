if(EXISTS "/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/build/tests/benchmark/bench_tests-b12d07c.cmake")
  include("/afs/cern.ch/user/n/nipinto/public/FCCAnalyses_MELA/build/tests/benchmark/bench_tests-b12d07c.cmake")
else()
  add_test(bench_NOT_BUILT-b12d07c bench_NOT_BUILT-b12d07c)
endif()