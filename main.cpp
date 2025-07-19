#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <curl/curl.h>
#include <cstring>
#include <sstream>
#include <iomanip>

std::string getCurrentTimestamp() {
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
        now.time_since_epoch()) % 1000;

    std::tm tm = *std::gmtime(&time);

    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%dT%H:%M:%S");
    oss << '.' << std::setw(3) << std::setfill('0') << ms.count() << "Z";
    return oss.str();
}

std::string getEnvValue(const std::string& key) {
    const char* val = std::getenv(key.c_str());
    return val ? std::string(val) : "";
}

std::string generateRandomJson() {
    int edgeId = rand() % 10;
    std::string tag = "DC_out_100ms[" + std::to_string(rand() % 200) + "]";
    std::string timestamp = getCurrentTimestamp();
    float value = static_cast<float>(rand()) / RAND_MAX * 100.0f;

    std::ostringstream oss;
    oss << "{";
    oss << "\"edgeId\":" << edgeId << ",";
    oss << "\"tag\":\"" << tag << "\",";
    oss << "\"timestamp\":\"" << timestamp << "\",";
    oss << "\"value\":" << value;
    oss << "}";

    return oss.str();
}

void sendRequest(const std::string& url, const std::string& token) {
    CURL* curl = curl_easy_init();
    if (curl) {
        std::string json = generateRandomJson();
        struct curl_slist* headers = NULL;

        std::string authHeader = "Authorization: Bearer " + token;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        headers = curl_slist_append(headers, authHeader.c_str());

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        curl_easy_perform(curl);
        curl_slist_free_all(headers);

    }
}

int main() {
    curl_global_init(CURL_GLOBAL_DEFAULT);
    srand(time(0));

    std::string apiUrl = getEnvValue("API_URL");
    std::string token = getEnvValue("INFRA_SECRET_KEY");

    if (apiUrl.empty() || token.empty()) {
        std::cerr << "Error: API_URL or INFRA_SECRET_KEY not found in environment variables" << std::endl;
        return 1;
    }

    while (true) {
        auto cycleStart = std::chrono::high_resolution_clock::now();

        sendRequest(apiUrl, token);

        auto cycleEnd = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsed = cycleEnd - cycleStart;

        

        auto remaining = std::chrono::milliseconds(500) - std::chrono::duration_cast<std::chrono::milliseconds>(elapsed);
        if (remaining.count() > 0) {
            std::this_thread::sleep_for(remaining);
        }
        std::cout << " Req time: " << elapsed.count()+remaining.count() << " ms " << std::endl;
    }

    curl_global_cleanup();
    return 0;
}
