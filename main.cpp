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
#include <map>

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

std::string trim(const std::string &str) {
    size_t start = str.find_first_not_of(" \t");
    if (start == std::string::npos) return "";
    size_t end = str.find_last_not_of(" \t");
    return str.substr(start, end - start + 1);
}

int parseInt(const std::string &str) {
    return std::stoi(trim(str));
}

std::map<std::string, std::map<std::string, int>> readConfig(const std::string &filename) {
    std::map<std::string, std::map<std::string, int>> config;
    std::ifstream file(filename);
    std::string line;
    std::string currentKey;
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file '" << filename << "'.\n";
        return config;
    }
    while (std::getline(file, line)) {
        line = trim(line);
        
        if (line.empty() || line[0] == '#') continue;
        if (line.front() == '[' && line.back() == ']') {
            currentKey = line;
            continue;
        }
        size_t eqPos = line.find('=');
        if (eqPos != std::string::npos) {
            std::string key = trim(line.substr(0, eqPos));
            std::string value = trim(line.substr(eqPos + 1));
            try {
                config[currentKey][key] = parseInt(value);
            } catch (const std::invalid_argument&) {
                std::cerr << "Warning: Invalid integer value for key '" << key << "' in section '" << currentKey << "'.\n";
            } catch (const std::out_of_range&) {
                std::cerr << "Warning: Integer value out of range for key '" << key << "' in section '" << currentKey << "'.\n";
            }
        }
    }
    return config;
}

std::string getEnvValue(const std::string& key) {
    const char* val = std::getenv(key.c_str());
    return val ? std::string(val) : "";
}
std::string generateJsonFor144(int edgeId){
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
std::string generateJsonFor146(int edgeId){
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
std::string generateJsonFor148(int edgeId){
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
std::string generateJsonFor164(int edgeId){
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
std::string generateJsonFor165(int edgeId){
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
std::string generateJsonFor140_8(int edgeId){
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
std::string generateJsonFor140_10(int edgeId){
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
std::string generateJsonFor140_9(int edgeId){
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
std::string generateJsonFor141_8(int edgeId){
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
std::string generateJsonFor141_9(int edgeId){
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
std::string generateJsonFor141_10(int edgeId){
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
std::string generateJsonFor140_13(int edgeId){
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
std::string generateJsonFor140_14(int edgeId){
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
std::string generateJsonFor141_13(int edgeId){
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

std::string generateJsonForTag(std::string tagKey, std::map<std::string, int> tag, int edgeId){
    std::string timestamp = getCurrentTimestamp();
    int value = tag["min"] + rand()%(tag["max"]-tag["min"]+1);
    
    std::ostringstream oss;
    oss << "{";
    oss << "\"edgeId\":" << edgeId << ",";
    oss << "\"tag\":\"DC_out_100ms"<<tagKey<<"\",";
    oss << "\"timestamp\":\"" << timestamp << "\",";
    oss << "\"value\":" << value;
    oss << "}";
    return oss.str();
}

std::string generateRandomJson(std::map<std::string, std::map<std::string, int>> tags) {
    int edgeId = 1 + rand() % 10;
    std::ostringstream oss;
    oss << "{";
    oss << "\"data\":[";
    for (const std::pair<std::string, std::map<std::string, int>>& section : tags) {
        std::string subJson = generateJsonForTag(section.first, section.second, edgeId);
        oss << subJson;
        oss << ",";
    }
    std::string str = oss.str();
    if (!str.empty()) {
        str.erase(str.size() - 1); 
    }
    oss.str(str);
    oss.clear();
    oss << "]";
    oss << "}";
    return oss.str();
}

void sendRequests(const std::string& url, const std::string& token, std::map<std::string, std::map<std::string, int>> tags) {
    CURL* curl = curl_easy_init();
    if (curl) {
        std::string json = generateRandomJson(tags);
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
    std::map<std::string, std::map<std::string, int>> tags;
    tags = readConfig("config.txt");
    curl_global_init(CURL_GLOBAL_DEFAULT);
    srand(time(0));
    int counte = 0;
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
            sendRequests(apiUrl, token, tags);
        }
        auto cycleEnd = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsed = cycleEnd - cycleStart;
        auto remaining = std::chrono::milliseconds(500) - std::chrono::duration_cast<std::chrono::milliseconds>(elapsed);
        if (remaining.count() > 0) {
            std::this_thread::sleep_for(remaining);
        }
        std::cout<<std::endl <<"-----"<<std::endl<< " Req time: " << elapsed.count()+remaining.count() << " ms "<<std::endl <<"-----" << std::endl;
    }

    curl_global_cleanup();
    return 0;
}
