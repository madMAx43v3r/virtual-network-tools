cmake_minimum_required(VERSION 2.4)

include_directories(include/)

ADD_LIBRARY(vni STATIC
	src/vnl/Announce.cxx
	src/vnl/DatabaseSupport.cxx
	src/vnl/DuplicateKeyException.cxx
	src/vnl/Exception.cxx
	src/vnl/Exit.cxx
	src/vnl/Header.cxx
	src/vnl/IOException.cxx
	src/vnl/Instance.cxx
	src/vnl/LogMsg.cxx
	src/vnl/NoSuchFieldException.cxx
	src/vnl/NoSuchKeyException.cxx
	src/vnl/NoSuchMethodException.cxx
	src/vnl/ObjectSupport.cxx
	src/vnl/PlayerSupport.cxx
	src/vnl/ProcessSupport.cxx
	src/vnl/RecordHeader.cxx
	src/vnl/RecordValue.cxx
	src/vnl/RecorderSupport.cxx
	src/vnl/Shutdown.cxx
	src/vnl/SpyToolSupport.cxx
	src/vnl/TcpClientSupport.cxx
	src/vnl/TcpProxySupport.cxx
	src/vnl/TcpServerSupport.cxx
	src/vnl/TcpUplinkSupport.cxx
	src/vnl/Topic.cxx
	src/vnl/UdpServerSupport.cxx
	src/vnl/UplinkSupport.cxx
	src/vnl/Value.cxx
	src/vnl/info/PlayerStatus.cxx
	src/vnl/tools/ReplayGUISupport.cxx
)

