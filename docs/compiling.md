The Forgotten Server can be compiled on a variety of operating systems. We currently provide build instructions for the following systems:
* [Compiling on Arch Linux](Compiling on Arch Linux.md)
* [Compiling on Debian GNU/Linux](Compiling on Debian GNU/Linux.md)
* [Compiling on Fedora](Compiling on Fedora.md)
* [Compiling on FreeBSD](Compiling on FreeBSD.md)
* [Compiling on Gentoo](Compiling on Gentoo.md)
* [Compiling on Mac OS X](Compiling on Mac OS X.md)
* [Compiling on Ubuntu](Compiling on Ubuntu.md)
* [Compiling on Windows](Compiling on Windows.md)

No worries if your system is not listed above, chances are that it can be compiled on your system anyway, but you will have to download and install the required software and libraries on your own. If your system has a package manager, you could save a couple of hours by installing them from the package manager instead of manually downloading and compiling the packages from their respective websites.

To download the source code, you will need [Git](http://git-scm.com/) (alternatively download a copy from GitHub and skip this step). Once you have installed Git, run this command to download a copy of the source code:

	$ git clone https://github.com/otland/forgottenserver.git

To compile the required libraries and The Forgotten Server, you will need a compiler and a set of libraries. We recommend [GCC](http://gcc.gnu.org/) or [Clang](http://clang.llvm.org/).

You will have to install [CMake](http://www.cmake.org/) to generate build files for your compiler.

The following libraries are required to compile The Forgotten Server:
* [Boost](https://boost.org/)
* [GMP](https://gmplib.org/)
* [Lua](http://www.lua.org/)
* [MySQL C connector](https://dev.mysql.com/downloads/connector/c/)
* [PugiXML](http://pugixml.org/)

Once you have installed all the libraries, create a directory with the name "build" in the root directory of the forgottenserver directory that you downloaded using Git. Now target the parent directory from the build directory using CMake to generate the build files. If you are using the CMake GUI, it could look like this:

	"Where is the source code: ~/forgottenserver"
	"Where to build the binaries: ~/forgottenserver/build/"

If you are using a command-line interface it could look like this:

	user@host:~/projects/forgottenserver/build$ cmake ..

After successfully running CMake, your compiler should be ready to compile The Forgotten Server from the build files generated in the build directory.