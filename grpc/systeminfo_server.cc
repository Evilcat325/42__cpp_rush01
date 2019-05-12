#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>
#include "systeminfo.grpc.pb.h"

using google::protobuf::Empty;
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

using systeminfo::CPUBaseInfoReply;
using systeminfo::SysInfo;

class SysInfoServiceImpl final : public SysInfo::Service
{
	Status GetCPUBase(ServerContext *context, const Empty *request,
										CPUBaseInfoReply *reply) override
	{
		reply->set_brand_string("CPU");
		reply->set_core_count(4);
		reply->set_thread_count(4);
		return Status::OK;
	}
};

void RunServer()
{
	std::string server_address("0.0.0.0:50051");
	SysInfoServiceImpl service;

	ServerBuilder builder;
	builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
	// Register "service" as the instance through which we'll communicate with
	// clients. In this case it corresponds to an *synchronous* service.
	builder.RegisterService(&service);
	// Finally assemble the server.
	std::unique_ptr<Server> server(builder.BuildAndStart());
	std::cout << "Server listening on " << server_address << std::endl;
	server->Wait();
}

int main()
{
	RunServer();
	return 0;
}
