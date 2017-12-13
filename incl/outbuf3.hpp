#include <cstdio>
#include <streambuf>
#include <ostream>


class outbuf : public std::streambuf
{
protected:
    static constexpr size_t bufSize = 10;
    FILE* file_;
    char buffer_[bufSize];

public:
    /* constructor
     * - initialize data buffer
     * - one character less to let the bufSize'th character cause 
     * - a call of overflow() */
    explicit outbuf( FILE* file )
        : file_( file )
        { setp( buffer_, buffer_+(bufSize-1)); }

    /* destructor - flush data buffer */
    virtual ~outbuf() noexcept
        { sync(); }

protected:
    // flush the characters in the buffer
    int flushBuffer()
        {
            int num = pptr() - pbase();
            if( fwrite( buffer_, sizeof(char), num, file_ ) != num ){
                return traits_type::eof();
            }
            pbump(-num);
            return num;
        }

    /* buffer full - write c and all previous characters */
    virtual int_type overflow( int_type c )
        {
            if( c != traits_type::eof() ){
                // insert character into the buffer
                *pptr() = c;
                pbump(1);
            }
            // flush the buffer
            if( flushBuffer() == traits_type::eof() ){
                // error
                return traits_type::eof();
            }
            return c;
        }

    /* synchronize data with file/destination
     * flush the data in the buffer */
    virtual int sync()
        {
            if( flushBuffer() == traits_type::eof() ){
                // error
                return -1;
            }
            return 0;
        }
};

/* inheriting privatly from outbuf ensures that it is constructed
 * before the ostream subobject and this object.
 * This lets as pass 'this' safely to the ostream constructor */
class outbufstream : private outbuf, public std::ostream
{
public:
    outbufstream( FILE* file )
        : outbuf(file), std::ostream(this) { }
};
