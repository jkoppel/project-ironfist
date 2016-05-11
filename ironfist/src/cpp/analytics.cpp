#include <WinSock2.h>

#include "Poco/Net/HTTPClientSession.h"
#include "Poco/Net/HTTPRequest.h"
#include "Poco/URI.h"

#include "analytics.h"
#include "base.h"
#include "gui/dialog.h"
#include "prefs.h"

// For UUID handling
#pragma comment(lib, "rpcrt4.lib") 

const std::string IRONFIST_TRACKER_ID("UA-24357556-4");

std::string createOrGetUuid() {
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
	return sUuid;
}

void send_event(const char* category, const char* action) {

	static std::string Uuid = createOrGetUuid();

	Poco::Net::HTTPClientSession session("www.google-analytics.com");
	Poco::Net::HTTPRequest req(Poco::Net::HTTPRequest::HTTP_POST, "/collect", Poco::Net::HTTPMessage::HTTP_1_1);
	Poco::URI uri("");
	uri.addQueryParameter("v", "1");
	uri.addQueryParameter("tid", IRONFIST_TRACKER_ID);
	uri.addQueryParameter("cid", Uuid);
	uri.addQueryParameter("t", "event");
	uri.addQueryParameter("an", "Ironfist");
	uri.addQueryParameter("ec", category);
	uri.addQueryParameter("ea", action);
	uri.addQueryParameter("el", Uuid);
	req.setContentLength(uri.getRawQuery().length());
	session.sendRequest(req) << uri.getRawQuery();

}