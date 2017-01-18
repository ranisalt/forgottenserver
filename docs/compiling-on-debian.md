The Forgotten Server requires at least gcc 4.8, which is available in Debian 8 (jessie).  

#### 1. Install the required software

The following command will install Git, CMake, a compiler and the libraries used by The Forgotten Server.

Git will be used to download the source code, and CMake will be used to generate the build files.

	# apt-get install git cmake build-essential liblua5.2-dev libgmp3-dev libmysqlclient-dev libboost-system-dev libboost-iostreams-dev libpugixml-dev

#### 2. Download the source code

	$ git clone https://github.com/otland/forgottenserver.git

#### 3. Generate the build files

	$ cd forgottenserver
	$ mkdir build && cd build
	$ cmake ..

#### 4. Build

	$ make