#include <iostream>
#include <string>
#include <curl/curl.h>
#include <thread>

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t totalSize = size * nmemb;
    output->append((char*)contents, totalSize);
    return totalSize;
}

std::string grab_temperature() {
    CURL* curl;
    CURLcode res;
    std::string buffer;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://wttr.in/?format=%f");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if (res == CURLE_OK) {
          return buffer;
        } 
    }
    return "";
}

void update_winbar(std::string temperature) {
  std::cout << "set_text_as_icon \""+ temperature + "\"" << std::endl;
  std::cout << "resize_me" << std::endl;
  return;
}

int main() {

    std::cout << "ui_start" << std::endl;
    std::cout << "layout_horizontal" << std::endl;
    std::cout << "ui_end" << std::endl;

    while (true) {
      update_winbar(grab_temperature());
      std::this_thread::sleep_for(std::chrono::minutes(3));
    }
    return 0;
}
