#include <WinSock2.h>

#include "Poco/Net/HTTPClientSession.h"
#include "Poco/Net/HTTPRequest.h"
#include "Poco/URI.h"
#include "Poco/UUID.h"
#include "Poco/UUIDGenerator.h"

#include "analytics.h"
#include "base.h"
#include "prefs.h"

extern const std::string gameAction = "gameAction";
extern const std::string mapAction = "mapAction";
extern const std::string open = "open";

const std::string IRONFIST_TRACKER_ID("UA-24357556-4");
bool internetDetected = true;

const std::string createOrGetUuid() {
	std::string uuid;
	bool getUuid = read_pref<std::string>("Uuid", uuid);
	if (!getUuid) {
		Poco::UUID pocoUuid = Poco::UUIDGenerator().create();
		uuid = pocoUuid.toString();
		bool setUuid = write_pref("Uuid", uuid);
	}
	return uuid;
}

void send_event_with_internet(const std::string &category, const std::string &action) {
	static const std::string uuid = createOrGetUuid();
	Poco::Net::HTTPClientSession session("www.google-analytics.com");
	Poco::Net::HTTPRequest req(Poco::Net::HTTPRequest::HTTP_POST, "/collect", Poco::Net::HTTPMessage::HTTP_1_1);
	Poco::URI uri("");
	uri.addQueryParameter("v", "1");
	uri.addQueryParameter("tid", IRONFIST_TRACKER_ID);
	uri.addQueryParameter("cid", uuid);
	uri.addQueryParameter("t", "event");
	uri.addQueryParameter("an", "Ironfist");
	uri.addQueryParameter("ec", category);
	uri.addQueryParameter("ea", action);
	uri.addQueryParameter("el", uuid);
	req.setContentLength(uri.getRawQuery().length());
	session.sendRequest(req) << uri.getRawQuery();
}

void send_event(const std::string &category, const std::string &action) {
	if (internetDetected) {
		try {
			send_event_with_internet(category, action);
		}
		catch (...) {
			internetDetected = false;
		}
	}
}