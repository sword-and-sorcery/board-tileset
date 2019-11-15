from conans import ConanFile, CMake

class UIBoardGame(ConanFile):
    name = "ui-board_game"
    version = "0.0"

    settings = "os", "arch", "compiler", "build_type"
    options = {"shared": [True, False]}
    default_options = {"shared": False}

    generators = "cmake"

    scm = {"type": "git",
           "url": "auto",
           "revision": "auto"}

    def requirements(self):
        self.requires("rapidxml/1.13@bincrafters/stable")
        self.requires("boost/1.69.0@conan/stable")
        self.requires("core-communications/0.0@sword/sorcery")
        self.requires("ui-tileset-glfw/0.0@sword/sorcery")
        self.requires("zlib/1.2.11", override=True)

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
        cmake.install()

    def package(self):
        self.copy("LICENSE", dst="licenses")

    def package_info(self):
        self.cpp_info.libs = ["board_game",]
