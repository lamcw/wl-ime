project('wlime', 'c',
  version : '0.0.0',
  default_options : [
    'c_std=c11',
    'warning_level=3',
    'werror=true'
  ],
  license : 'MIT'
)

scdoc = find_program('scdoc', required : get_option('man'))
if scdoc.found()
  sh = find_program('sh')
  mandir = get_option('mandir')
  man_files = [
    'docs/wlime.1.scd'
  ]

  foreach filename : man_files
    topic = filename.split('.')[-3].split('/')[-1]
    section = filename.split('.')[-2]
    output = '@0@.@1@'.format(topic, section)
    custom_target(
      output,
      input : filename,
      output : output,
      command : [
	sh, '-c', '@0@ < @INPUT@ > @1@'.format(scdoc.path(), output)
      ],
      install : true,
      install_dir : '@0@/man@1@'.format(mandir, section)
    )
  endforeach
endif

add_project_arguments('-D_POSIX_C_SOURCE=200809L', language : 'c')

wayland_client = dependency('wayland-client')
wayland_protocols = dependency('wayland-protocols')

incdir = include_directories('include')

subdir('src')
subdir('protocol')
subdir('tests')

exe = executable(
  'wlime',
  wlime_sources,
  dependencies : [
    wayland_protocols
  ],
  include_directories : incdir,
  install : true
)
