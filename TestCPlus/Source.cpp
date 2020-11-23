#include <iostream>
#include <aspose_ocr.h>
#include <filesystem>
#include <corecrt_io.h>
#include <fcntl.h>

int main()
{
    _setmode(_fileno(stdout), _O_U16TEXT);

    //Current directory
    const std::filesystem::path path{ std::filesystem::current_path() };

    /* asposeocr_set_license */

  /*  const std::string lic = "/Aspose.Total.lic";
    std::filesystem::path license = path.string() + lic;
    asposeocr_set_license(license.string().c_str());*/

    /* asposeocr_set_license */

    //bool lic_result = asposeocr_get_state();

    //Recognize image
    std::filesystem::path image = path.string() + "/figure-65.png";

    // Prepare buffer for result (in symbols, len_byte = len * sizeof(wchar_t))
    const size_t len = 4096;
    wchar_t buffer[len] = { 0 };

    /* asposeocr_page */
    size_t res_len = asposeocr_page(image.string().c_str(), buffer, len);

    //Print result
    std::wcout << buffer << L"\n";

    /* asposeocr_page_all */
    res_len = asposeocr_page_all(image.string().c_str(), buffer, len, true);

    //Print result
    std::wcout << buffer << L"\n";

    /* asposeocr_page_rect */
    //int x = 138, y = 352, w = 2033, h = 537;
    //size_t size = asposeocr_page_rect(image.string().c_str(), buffer, len, x, y, w, h);
    //std::wcout << buffer << L"\n";

    ///* asposeocr_page_abc */
    //size = asposeocr_page_abc(image.string().c_str(), buffer, len,
    //    L" !\",#$%&()*+,-./0123456789:;<=>?@[\\]_`{|}"
    //    "~ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
    //std::wcout << buffer << L"\n";

    ///* asposeocr_page_abc_all */
    //size = asposeocr_page_abc_all(image.string().c_str(), buffer, len,
    //    L" !\",#$%&()*+,-./0123456789:;<=>?@[\\]_`{|}"
    //    "~ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz", false);
    //std::wcout << buffer << L"\n";

    ///* asposeocr_page_rect_abc */
    //size = asposeocr_page_rect_abc(image.string().c_str(), buffer, len, x, y, w, h,
    //    L" !\",#$%&()*+,-./0123456789:;<=>?@[\\]_`{|}"
    //    "~ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

    //std::wcout << buffer << L"\n";

    //std::string f = path.string() + "/0001460985.Jpeg";

    ///* asposeocr_line */
    //size = asposeocr_line(f.c_str(), buffer, len);
    //std::wcout << buffer;

    /* asposeocr_line_abc */
   /* size_t size = asposeocr_line_abc(f.c_str(), buffer, len, L"0123456789");
    std::wcout << buffer;*/
}
