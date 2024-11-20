module;
#include <boost/type_index.hpp>
#include <boost/filesystem.hpp>

//

#include <boost/log/core/record_view.hpp>
#include "boost/log/expressions.hpp"
#include "boost/log/sources/severity_channel_logger.hpp"
#include <boost/log/sinks.hpp>

#include <boost/log/sinks/basic_sink_backend.hpp>
#include <boost/log/sinks/frontend_requirements.hpp>
#include <boost/log/utility/manipulators/add_value.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/expressions/predicates/is_debugger_present.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/expressions/attr_fwd.hpp>
#include <boost/log/expressions/attr.hpp>
#include <boost/log/attributes.hpp>
#include <boost/log/common.hpp>

#include <boost/log/sources/global_logger_storage.hpp>


#include <boost/log/core.hpp>

#include <boost/log/sources/logger.hpp>
export module Module;

BOOST_LOG_INLINE_GLOBAL_LOGGER_DEFAULT(GGG_logger, boost::log::sources::severity_channel_logger_mt<boost::log::trivial::severity_level>);


#define LOG_DEBUG1(ch) BOOST_LOG_CHANNEL_SEV(GGG_logger::get(), ch, boost::log::trivial::debug)

#define LOG_DEBUG_DEFAULT LOG_DEBUG1(SIMPLE_DEFAULT_CHANNEL_NAME)



export namespace net::winui {
	class LoggerPrivate {
	public:
		LoggerPrivate() :mStream(mStr) {

		}
		~LoggerPrivate() {
			{

				LOG_DEBUG1("dsds") << mStream.str() << std::endl; //  error C1907 

			}
		
			mStream.flush();

			mStr.clear();

		}

		
	private:


		boost::log::formatting_ostream mStream;

		std::string mStr;

	};
}