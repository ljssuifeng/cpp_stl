#include <iomanip>
#include <iostream>

int main() {
  using std::ios;
  using std::cout;

  // saving current format flags
  ios::fmtflags oldFlags = cout.flags();
  // do some changes
  cout.setf(ios::showpos | ios::showbase | ios::uppercase);
  cout.setf(ios::internal, ios::adjustfield);
  int x = 345;
  cout << std::setw(20) << std::setfill('*') << std::hex << x << std::endl;

  // restore saved format flags
  cout.flags(oldFlags);

  bool b{false};
  cout << std::noboolalpha << b << "==" << std::boolalpha << b << std::endl;

  cout << 12345678.9 << std::endl;
  cout.setf(std::ios::showpos | std::ios::uppercase);
  cout << 12345678.9 << std::endl;

  cout.unsetf(ios::dec);
  cout.setf(ios::hex);

  cout << 127 << ' ' << 255 << std::endl;
  cout << std::hex << 127 << ' ' << 255 << std::endl;
  cout.setf(ios::showbase);  // 0x
  cout.unsetf(ios::uppercase);
  cout << 127 << ' ' << 255 << std::endl;
  cout.setf(ios::uppercase);
  cout << 127 << ' ' << 255 << std::endl;

  // floating point
  std::cout << std::scientific << std::showpoint << std::setprecision(8)
            << 0.123456789 << std::endl;

  // genreal formating
  // skipws: ignore blanks at the head
  // unitbuf: flush output buffer
}
