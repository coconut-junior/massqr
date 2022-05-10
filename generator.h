using std::uint8_t;
using qrcodegen::QrCode;
using qrcodegen::QrSegment;

static void doBasicDemo();
static void doVarietyDemo();
static void doSegmentDemo();
static void doMaskDemo();
static std::string toSvgString(const QrCode &qr, int border);
static void printQr(const QrCode &qr);
std::string toQR(const char * text);