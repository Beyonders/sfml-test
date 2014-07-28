
Dependencies
==================

 - SFML2
 - CMake
 

Linux
=========

	mkdir bin
	cd bin
	cmake ..
	make
	./sfml-test


Windows
=========

Example: 
 - Windows XP + Visual Studio Express 2008
 - working directory C:\work

Steps:
- download project ( C:\work\sfml-test )
- Install CMake
- Download SFML 2.1 for Visual Studio 2008 ( C:\work\SFML-2.1 )
- Copy SFML dlls in system32 directory ( C:\work\SFML-2.1\bin\*.dll -> C:\Windows\system32 )
- create build directory ( C:\work\sfml-test\build )
- open CMake and set all values ( http://postimg.org/image/bkqo0d89p/ )
   - set directories
   - add entry: SFML_ROOT ( C:\work\SFML-2.1 )
   - push "configure"
   - push "generate"
- open .sln in build directory with Visual Studio Express 2008
- set "sfml-test" project as "startup project"
- push "run"
