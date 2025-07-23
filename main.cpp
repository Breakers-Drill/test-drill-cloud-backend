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
std:string generateJsonFor144(int edgeId){
    std::string timestamp = getCurrentTimestamp();
    int value = rand()%2;
    
    std::ostringstream oss;
    oss << "{";
    oss << "\"edgeId\":" << edgeId << ",";
    oss << "\"tag\":\"DC_out_100ms[144]\",";
    oss << "\"timestamp\":\"" << timestamp << "\",";
    oss << "\"value\":" << value;
    oss << "}";
    return oss.str();
}
std:string generateJsonFor146(int edgeId){
    std::string timestamp = getCurrentTimestamp();
    int value = rand()%2;
    
    std::ostringstream oss;
    oss << "{";
    oss << "\"edgeId\":" << edgeId << ",";
    oss << "\"tag\":\"DC_out_100ms[146]\",";
    oss << "\"timestamp\":\"" << timestamp << "\",";
    oss << "\"value\":" << value;
    oss << "}";
    return oss.str();
}
std:string generateJsonFor148(int edgeId){
    std::string timestamp = getCurrentTimestamp();
    int value = 10 + rand()%41;
    
    std::ostringstream oss;
    oss << "{";
    oss << "\"edgeId\":" << edgeId << ",";
    oss << "\"tag\":\"DC_out_100ms[148]\",";
    oss << "\"timestamp\":\"" << timestamp << "\",";
    oss << "\"value\":" << value;
    oss << "}";
    return oss.str();
}
std:string generateJsonFor164(int edgeId){
    std::string timestamp = getCurrentTimestamp();
    int value = 20 + rand()%61;
    
    std::ostringstream oss;
    oss << "{";
    oss << "\"edgeId\":" << edgeId << ",";
    oss << "\"tag\":\"DC_out_100ms[164]\",";
    oss << "\"timestamp\":\"" << timestamp << "\",";
    oss << "\"value\":" << value;
    oss << "}";
    return oss.str();
}
std:string generateJsonFor165(int edgeId){
    std::string timestamp = getCurrentTimestamp();
    int value = 5 + rand()%21;
    
    std::ostringstream oss;
    oss << "{";
    oss << "\"edgeId\":" << edgeId << ",";
    oss << "\"tag\":\"DC_out_100ms[165]\",";
    oss << "\"timestamp\":\"" << timestamp << "\",";
    oss << "\"value\":" << value;
    oss << "}";
    return oss.str();
}
std:string generateJsonFor140_8(int edgeId){
    std::string timestamp = getCurrentTimestamp();
    int value = rand()%101;
    
    std::ostringstream oss;
    oss << "{";
    oss << "\"edgeId\":" << edgeId << ",";
    oss << "\"tag\":\"DC_out_100ms[140].8\",";
    oss << "\"timestamp\":\"" << timestamp << "\",";
    oss << "\"value\":" << value;
    oss << "}";
    return oss.str();
}
std:string generateJsonFor140_10(int edgeId){
    std::string timestamp = getCurrentTimestamp();
    int value = rand()%6;
    
    std::ostringstream oss;
    oss << "{";
    oss << "\"edgeId\":" << edgeId << ",";
    oss << "\"tag\":\"DC_out_100ms[140].10\",";
    oss << "\"timestamp\":\"" << timestamp << "\",";
    oss << "\"value\":" << value;
    oss << "}";
    return oss.str();
}
std:string generateJsonFor140_9(int edgeId){
    std::string timestamp = getCurrentTimestamp();
    int value = 50 + rand()%101;
    
    std::ostringstream oss;
    oss << "{";
    oss << "\"edgeId\":" << edgeId << ",";
    oss << "\"tag\":\"DC_out_100ms[140].9\",";
    oss << "\"timestamp\":\"" << timestamp << "\",";
    oss << "\"value\":" << value;
    oss << "}";
    return oss.str();
}
std:string generateJsonFor141_8(int edgeId){
    std::string timestamp = getCurrentTimestamp();
    int value = rand()%2;
    
    std::ostringstream oss;
    oss << "{";
    oss << "\"edgeId\":" << edgeId << ",";
    oss << "\"tag\":\"DC_out_100ms[141].8\",";
    oss << "\"timestamp\":\"" << timestamp << "\",";
    oss << "\"value\":" << value;
    oss << "}";
    return oss.str();
}
std:string generateJsonFor141_9(int edgeId){
    std::string timestamp = getCurrentTimestamp();
    int value = 15 + rand()%61;
    
    std::ostringstream oss;
    oss << "{";
    oss << "\"edgeId\":" << edgeId << ",";
    oss << "\"tag\":\"DC_out_100ms[141].9\",";
    oss << "\"timestamp\":\"" << timestamp << "\",";
    oss << "\"value\":" << value;
    oss << "}";
    return oss.str();
}
std:string generateJsonFor141_10(int edgeId){
    std::string timestamp = getCurrentTimestamp();
    int value = 100 + rand()%(101);
    
    std::ostringstream oss;
    oss << "{";
    oss << "\"edgeId\":" << edgeId << ",";
    oss << "\"tag\":\"DC_out_100ms[141].10\",";
    oss << "\"timestamp\":\"" << timestamp << "\",";
    oss << "\"value\":" << value;
    oss << "}";
    return oss.str();
}
std:string generateJsonFor140_13(int edgeId){
    std::string timestamp = getCurrentTimestamp();
    int value = rand()%(11);
    
    std::ostringstream oss;
    oss << "{";
    oss << "\"edgeId\":" << edgeId << ",";
    oss << "\"tag\":\"DC_out_100ms[140].13\",";
    oss << "\"timestamp\":\"" << timestamp << "\",";
    oss << "\"value\":" << value;
    oss << "}";
    return oss.str();
}
std:string generateJsonFor140_14(int edgeId){
    std::string timestamp = getCurrentTimestamp();
    int value = rand()%(501);
    
    std::ostringstream oss;
    oss << "{";
    oss << "\"edgeId\":" << edgeId << ",";
    oss << "\"tag\":\"DC_out_100ms[144]\",";
    oss << "\"timestamp\":\"" << timestamp << "\",";
    oss << "\"value\":" << value;
    oss << "}";
    return oss.str();
}
std:string generateJsonFor141_13(int edgeId){
    std::string timestamp = getCurrentTimestamp();
    int value = 5 + rand()%(46);
    
    std::ostringstream oss;
    oss << "{";
    oss << "\"edgeId\":" << edgeId << ",";
    oss << "\"tag\":\"DC_out_100ms[144]\",";
    oss << "\"timestamp\":\"" << timestamp << "\",";
    oss << "\"value\":" << value;
    oss << "}";
    return oss.str();
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

void sendRequests(const std::string& url, const std::string& token) {
    std::string (*generatorsArray[])(int) = {generateJsonFor144, generateJsonFor146, generateJsonFor148, generateJsonFor164, generateJsonFor165, generateJsonFor140_8, generateJsonFor140_10, generateJsonFor140_9, generateJsonFor141_8, generateJsonFor141_9, generateJsonFor141_10, generateJsonFor140_13, generateJsonFor140_14, generateJsonFor141_13};
    
    CURLM *multi_handle = curl_multi_init();
    int edgeId = rand() % 10;
    for (size_t i = 0; i < 15; ++i) {
        CURL* curl = curl_easy_init();
        if (curl) {
            std::string json = generatorsArray[i](edgeId);
            struct curl_slist* headers = NULL;
            std::string authHeader = "Authorization: Bearer " + token;
            headers = curl_slist_append(headers, "Content-Type: application/json");
            headers = curl_slist_append(headers, authHeader.c_str());
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json.c_str());
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
            curl_multi_add_handle(multi_handle, curl);
        }
    }
    
    curl_multi_perform(multi_handle, nullptr);
    curl_multi_cleanup(multi_handle);
    curl_slist_free_all(headers);
}

int main() {
    curl_global_init(CURL_GLOBAL_DEFAULT);
    srand(time(0));
    std::int counte = 0
    std::string apiUrl = getEnvValue("API_URL");
    std::string token = getEnvValue("INFRA_SECRET_KEY");
    std::string counteStr = getEnvValue("COUNTE_OF_DRILL");
    try{
        counte = std::stoi(counteStr);
    } catch(...){
        counte = 1;
    }
    if (apiUrl.empty() || token.empty()) {
        std::cerr << "Error: API_URL or INFRA_SECRET_KEY not found in environment variables" << std::endl;
        return 1;
    }

    while (true) {
        auto cycleStart = std::chrono::high_resolution_clock::now();
        for(int i=0;i<counte;i++){
            sendRequests(apiUrl, token);
        }
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
