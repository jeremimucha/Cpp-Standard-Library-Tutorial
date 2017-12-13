#include <cstdio>
#include <cstring>
#include <streambuf>
#include <istream>


class inbuf : public std::streambuf
{
protected:
    /* data buffer:
     * - at most two characters in putback area */
    static constexpr size_t bufSize = 10;
    static constexpr size_t putbackSize = 2;
    FILE* file_;
    char buffer_[bufSize];

public:
    /* ctor -- initialize empty data buffer, no putback area
     * - force underflow() */
    inbuf( FILE* file )
        : file_(file)
        {
            setg( buffer_+putbackSize,  // beginning of putback area -- eback()
                  buffer_+putbackSize,  // read position             -- gptr()
                  buffer_+putbackSize); // end position              -- egptr()
        }

protected:
    // insert new characters into the buffer
    virtual int_type underflow()
        {
            // is read position before end of buffer?
            if( gptr() < egptr() ){
                return traits_type::to_int_type(*gptr());
            }

            // process size of putback area
            // - use number of characters read
            // - but at most four
            int numPutback;
            numPutback = gptr() - eback();
            if( numPutback > putbackSize ){
                numPutback = putbackSize;
            }

            // copy up to putbackSize characters previously read into
            // the putback buffer (area of first putbackSize characters)
            std::memmove( buffer_+(putbackSize-numPutback),
                          gptr()-numPutback, numPutback );

            // read new characters
            int num = fread( buffer_+putbackSize, sizeof(char),
                             bufSize-putbackSize, file_ );
            if( num <= 0 ){
                return traits_type::eof();
            }

            // reset buffer pointers
            setg( buffer_+(putbackSize-numPutback),
                  buffer_+putbackSize,
                  buffer_+putbackSize+num );

            // return next character
            return traits_type::to_int_type(*gptr());
        }
};


class inbufstream : private inbuf, public std::istream
{
public:
    explicit inbufstream( FILE* file )
        : inbuf(file), std::istream(this) { }
};
