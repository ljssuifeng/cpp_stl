#include "ring_buffer.h"
#include <iterator>
#include <stdexcept>

// Initialize the vector to hold exactly numEntries. The vector size
// does not need to change druing the lifetime of the object.
// Initialize the other members.
RingBuffer::RingBuffer(size_t numEntries, std::ostream* ostr)
    : mEntries(numEntries), mOstr(ostr), mWrapped(false) {
  if (numEntries == 0) {
    throw std::invalid_argument("Number of entries must be >0.");
  }
  mNext = std::begin(mEntries);
}

// The addStringEntry algorithm is pretty simple: add the entry to the next
// free spot, then reset mNext to indicate the free sopt after
// that. If mNext reaches the end of the vector, it starts over at 0.
// the buffer needs to know if the buffer has wrapped or not so
// that it knows whether to print the entries past mNext in operator<<.
void RingBuffer::addStringEntry(std::string&& entry) {
  // If there is a valid ostream, write this entry to it
  if (mOstr) {
    *mOstr << entry << std::endl;
  }
  // Move the entry to the next free spot and increment
  // mNext to point to the free spot after that.
  *mNext = std::move(entry);
  ++mNext;

  // Check if we've reached the end of the buffer. If so, we need to wrap.
  if (mNext == std::end(mEntries)) {
    mNext = std::begin(mEntries);
    mWrapped = true;
  }
}

// Set the output stream
std::ostream* RingBuffer::setOutput(std::ostream* newOstr) {
  std::ostream* oldValue = std::move(mOstr);
  mOstr = newOstr;
  return oldValue;
}

std::ostream& operator<<(std::ostream& ostr, RingBuffer& rb) {
  if (rb.mWrapped) {
    std::copy(rb.mNext, std::end(rb.mEntries),
              std::ostream_iterator<std::string>(ostr, "\n"));
  }
  std::copy(std::begin(rb.mEntries), rb.mNext,
            std::ostream_iterator<std::string>(ostr, "\n"));
  return ostr;
}
