[private]
@list:
  just --list

@build:
  nix --extra-experimental-features "nix-command flakes" develop --profile .nix-profile --command ./run

@configure:
  nix --extra-experimental-features "nix-command flakes" develop --profile .nix-profile --command ./configure

@oink:
  grep oinkHatcher ver/us/build/papermario.map
