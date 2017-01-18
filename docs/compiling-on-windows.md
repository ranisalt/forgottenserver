#### 1. Download the required software

To compile The Forgotten Server on Windows, you will need:
* [Visual Studio 2015 Update 3](https://www.visualstudio.com/) (compiler)
* [TFS SDK v3.2](https://static.otland.net/dl/tfs-sdk-3.2.zip) (libraries)
 * sha1sum: 3fb1b140e40e8e8bc90f82f92bd022a50569b185
 * sha256sum: 2ffb549f336ad11550da9b9c40716880e13b1cc0ee86e7599022dcacc972a3bf
* Boost C++ libraries ([32-bit download](https://sourceforge.net/projects/boost/files/boost-binaries/1.62.0/boost_1_62_0-msvc-14.0-32.exe/download), [64-bit download](https://sourceforge.net/projects/boost/files/boost-binaries/1.62.0/boost_1_62_0-msvc-14.0-64.exe/download))

#### 2. Install the required software

Once you have downloaded the software listed in the step above, begin by installing Visual Studio and Boost C++ libraries. Extract TFS SDK anywhere on your computer and run the file "register_tfssdk_env.bat" to set the PATH environment variable for TFS SDK, so that the compiler can find the libraries once we get to compiling the source code. Move the file "register_boost_env.bat" from TFS SDK to the directory where you installed Boost C++ libraries and run it there (it should be in the directory called boost_1_62_0).

#### 3. Download the source code

If you have a Git client installed, you can clone the latest copy with this command:

	git clone https://github.com/otland/forgottenserver.git

If you don't have a Git client installed, you can download the latest copy of The Forgotten Server from this URL: https://github.com/otland/forgottenserver/archive/master.zip

#### 4. Build

Find the directory vc14 in the copy of The Forgotten Server that you downloaded, and open theforgottenserver.sln. This should launch Visual Studio, and you should be good to go.

To configure the build, navigate to Build -> Configuration Manager in the menu. A dialog should pop up where you can choose between Release or Debug build, and 32-bit (Win32) or 64-bit (x64) build.

To start compiling, open the Build menu again and click on Build Solution.