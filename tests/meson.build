munit = dependency('munit', fallback : ['munit', 'munit_dep'])

test_sources = files(
  'test.c'
)

test_exe = executable(
  'test_wlime', test_sources,
  dependencies : munit,
  include_directories : incdir
)

test('basic', test_exe)
