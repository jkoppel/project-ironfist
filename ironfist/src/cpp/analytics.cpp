#include "analytics.h"
#include "prefs.h"
#include "Poco/Net/HTTPClientSession.h"
#include "Poco/Net/HTTPRequest.h"
#include "gui/dialog.h"

// For UUID handling
#pragma comment(lib, "rpcrt4.lib") 

void send_event(char* category, char* action) {

	// Get the Uuid saved in the registry if it exists.
	// Create one otherwise
	std::string sUuid;
	bool getUuid = read_pref<std::string>("Uuid", sUuid);
	if (!getUuid) {
		UUID uuid;
		UuidCreate(&uuid);
		unsigned char * str;
		UuidToStringA(&uuid, &str);
		std::string s((char*)str);
		RpcStringFreeA(&str);
		sUuid = s;
		bool success = write_pref("Uuid", sUuid);
	}

	// Post on the GA server using POCO library
	Poco::Net::HTTPClientSession session("www.google-analytics.com");
	Poco::Net::HTTPRequest req(Poco::Net::HTTPRequest::HTTP_POST, "/collect", Poco::Net::HTTPMessage::HTTP_1_1);
	const char *s1 = "v=1&tid=UA-24357556-4&cid=";
	const char *s2 = "&t=event&an=Ironfist&ec=";
	const char *s3 = "&ea=";
	const char *s4 = "&el=";
	int len = strlen(s1) + strlen(s2) + strlen(s3) + strlen(s4) 
		+ strlen(category) + strlen(action) + 2 * sUuid.size() + 1;
	char *creqBody = (char *)ALLOC(len);
	snprintf(creqBody, len, "%s%s%s%s%s%s%s%s", s1, sUuid.c_str(), s2, category, s3, action, s4, sUuid.c_str());
	std::string reqBody(creqBody);
	req.setContentLength(reqBody.length());
	session.sendRequest(req) << reqBody;
}