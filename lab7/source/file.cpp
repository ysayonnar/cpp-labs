#include "../include/file.h"
#include "../include/exeptions/file_exception.h"

std::string File::get_filename() const { return filename; }

void File::set_filename(const std::string &filename) { this->filename = filename; }

void File::open(std::ios::openmode mode) {
    close();

    file.open(filename, mode);

    if (!file.is_open()) {
        throw FileException(51, "error while opening file", "general error");
    }

    if (file.fail()) {
        file.close();
        throw FileException(52, "Logical error while opening", "format_error");
    }

    if (file.bad()) {
        file.close();
        throw FileException(53, "Critical IO error while opening:", "critical_error");
    }
}

void File::close() {
    if (file.is_open()) {
        file.close();
    }
}

bool File::is_open() { return file.is_open(); }
