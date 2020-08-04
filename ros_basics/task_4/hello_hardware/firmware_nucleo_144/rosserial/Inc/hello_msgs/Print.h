#ifndef _ROS_hello_msgs_Print_h
#define _ROS_hello_msgs_Print_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hello_msgs
{

  class Print : public ros::Msg
  {
    public:
      typedef const char* _document_name_type;
      _document_name_type document_name;
      typedef const char* _content_type;
      _content_type content;

    Print():
      document_name(""),
      content("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_document_name = strlen(this->document_name);
      varToArr(outbuffer + offset, length_document_name);
      offset += 4;
      memcpy(outbuffer + offset, this->document_name, length_document_name);
      offset += length_document_name;
      uint32_t length_content = strlen(this->content);
      varToArr(outbuffer + offset, length_content);
      offset += 4;
      memcpy(outbuffer + offset, this->content, length_content);
      offset += length_content;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_document_name;
      arrToVar(length_document_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_document_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_document_name-1]=0;
      this->document_name = (char *)(inbuffer + offset-1);
      offset += length_document_name;
      uint32_t length_content;
      arrToVar(length_content, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_content; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_content-1]=0;
      this->content = (char *)(inbuffer + offset-1);
      offset += length_content;
     return offset;
    }

    const char * getType(){ return "hello_msgs/Print"; };
    const char * getMD5(){ return "713bd55dae5863c2e7a116c221866c93"; };

  };

}
#endif