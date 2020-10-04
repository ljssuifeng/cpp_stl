#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class RingBuffer {
 public:
  // constructs a ring buffer with space for numEntries
  // Entries are written to *ostr as they are queued (optional).
  explicit RingBuffer(size_t numEntries = kDefaultNumEntries,
                      std::ostream* ostr = &std::cout);
  virtual ~RingBuffer() = default;

  // Adds an entry to the ring buffer, possibly overwriting the
  // oldest entry in the buffer (if the buffer is full).
  void addEntry(const std::string& args) { addStringEntry(args.c_str()); }

  // Streams the buffer entries, separated by newline, to ostr
  friend std::ostream& operator<<(std::ostream& ostr, RingBuffer& rb);

  // Streams entries as they are added to the given streams
  // Specify nullptr to disable this feature
  // Returns the old output stream
  std::ostream* setOutput(std::ostream* newOstr);

 private:
  std::vector<std::string> mEntries;
  std::vector<std::string>::iterator mNext;
  std::ostream* mOstr;
  bool mWrapped;
  static const size_t kDefaultNumEntries = 500;
  void addStringEntry(std::string&& entry);
};
