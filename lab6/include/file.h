#ifndef FILE_H
#define FILE_H

#include <fstream>
#include <string>

class File {
  protected:
    std::string filename;

  public:
    std::fstream file;

    File(const std::string &filename) : filename(filename) {};
    virtual ~File() { close(); };

    std::string get_filename() const;
    void set_filename(const std::string &filename);

    // throws exceptions
    void open(std::ios::openmode mode = std::ios::in | std::ios::out);
    void close();
    bool is_open();

  private:
    File(const File &) = delete;
    File &operator=(const File &) = delete;
};

#endif // FILE_H