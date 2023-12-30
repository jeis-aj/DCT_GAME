

cc = arduino-cli
flags = --warnings all
port = /dev/ttyACM0
board = arduino:avr:uno
build  = build
src = GunBoard 

all : compile upload

compile:
	$(cc) compile  --fqbn $(board) --build-path $(build)  $(src)   $(flags)

upload: 
	$(cc) upload -p $(port) --fqbn $(board) --input-dir $(build)

clean:
	rm -rf build

.PHONY = all compile upload
