# Install
First, you must put a The Legend of Zelda: The Minish Cap (U) ROM (with SHA1: `b4bd50e4131b027c334547b4524e2dbbd4227130`) in the root directory of the repository and name it `baserom.gba`.

## Building other variants
To build other variants, you need to place the corresponding baserom before building, e.g. `baserom_jp.gba` for JP.

## Prerequisites

| Linux | macOS | Windows 10 (build 18917+) | Windows 10 (1709+) | Windows 8, 8.1, and 10 (1507, 1511, 1607, 1703)
| ----- | ----- | ------------------------- | ------------------ | ---------------------------------------------------------
| none | [Xcode Command Line Tools package][xcode] | [Windows Subsystem for Linux 2][wsl2] | [Windows Subsystem for Linux][wsl] | [Cygwin][cygwin]

[xcode]: https://developer.apple.com/library/archive/technotes/tn2339/_index.html#//apple_ref/doc/uid/DTS40014588-CH1-DOWNLOADING_COMMAND_LINE_TOOLS_IS_NOT_AVAILABLE_IN_XCODE_FOR_MACOS_10_9__HOW_CAN_I_INSTALL_THEM_ON_MY_MACHINE_
[wsl2]: https://docs.microsoft.com/windows/wsl/wsl2-install
[wsl]: https://docs.microsoft.com/windows/wsl/install-win10
[cygwin]: https://cygwin.com/install.html

The [prerelease version of the Linux subsystem](https://docs.microsoft.com/windows/wsl/install-legacy) available in the 1607 and 1703 releases of Windows 10 is obsolete so consider uninstalling it.

Make sure that the `build-essential`, `git`, and `libpng-dev` packages are installed. The `build-essential` package includes the `make`, `gcc-core`, and `g++` packages so they do not have to be obtained separately.

In the case of Cygwin, [include](https://cygwin.com/cygwin-ug-net/setup-net.html#setup-packages) the `make`, `git`, `gcc-core`, `gcc-g++`, and `libpng-devel` packages.

Install the **devkitARM** toolchain of [devkitPro](https://devkitpro.org/wiki/Getting_Started) and add its environment variables. For Windows versions without the Linux subsystem, the devkitPro [graphical installer](https://github.com/devkitPro/installer/releases) includes a preconfigured MSYS2 environment, thus the steps below are not required.

    sudo (dkp-)pacman -S gba-dev
    export DEVKITPRO=/opt/devkitpro
    echo "export DEVKITPRO=$DEVKITPRO" >> ~/.bashrc
    export DEVKITARM=$DEVKITPRO/devkitARM
    echo "export DEVKITARM=$DEVKITARM" >> ~/.bashrc

## Installation

To set up the repository:

	git clone https://github.com/zeldaret/tmc
	git clone https://github.com/pret/agbcc

	cd ./agbcc
	sh build.sh
	sh install.sh ../tmc

	cd ../tmc
	make setup

To build **tmc.gba**:

	make -j$(nproc)

If only `.c` or `.s` files were changed, turn off the dependency scanning temporarily. Changes to any other files will be ignored and the build will either fail or not reflect those changes.

	make -j$(nproc) NODEP=1

**Note:** If the build command is not recognized on Linux, including the Linux environment used within Windows, run `nproc` and replace `$(nproc)` with the returned value (e.g.: `make -j4`). Because `nproc` is not available on macOS, the alternative is `sysctl -n hw.ncpu`.

### Note for Mac users

The BSD make that comes with Mac XCode can be buggy, so obtain GNU make and sed using [Homebrew](https://brew.sh):

	brew install make gnu-sed

When compiling agbcc, substitute the `build.sh` line for

	gsed 's/^make/gmake/g' build.sh | sh

Finally, use `gmake` instead of `make` to compile the ROM(s).
