wl_protocol_dir = wayland_protocols.get_pkgconfig_variable('pkgdatadir')

wayland_scanner = find_program('wayland-scanner')

wayland_scanner_code = generator(
  wayland_scanner,
  output : '@BASENAME@-protocol.c',
  arguments : ['private-code', '@INPUT@', '@OUTPUT@']
)

wayland_scanner_client = generator(
  wayland_scanner,
  output : '@BASENAME@-client-protocol.h',
  arguments : ['client-header', '@INPUT@', '@OUTPUT@']
)

client_protocols = [
  [wl_protocol_dir, 'stable/xdg-shell/xdg-shell.xml'],
  [wl_protocol_dir, 'unstable/xdg-output/xdg-output-unstable-v1.xml'],
]

client_protocols_src = []
client_protocols_headers = []

foreach p : client_protocols
  xml = join_paths(p)
  client_protocols_src += wayland_scanner_code.process(xml)
  client_protocols_headers += wayland_scanner_client.process(xml)
endforeach

lib_client_protocols = static_library(
  'client_protocols',
  client_protocols_src + client_protocols_headers,
  dependencies : wayland_client
)

declare_dependency(
  link_with : lib_client_protocols,
  sources   : client_protocols_headers
)
