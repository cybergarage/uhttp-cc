/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef _UHTTP_PARAMETERLIST_H_
#define _UHTTP_PARAMETERLIST_H_

#include <uhttp/util/Vector.h>
#include <uhttp/util/StringUtil.h>
#include <uhttp/http/Parameter.h>

namespace uHTTP {

class ParameterList : public ::uHTTP::SharedVector<Parameter> {
public:
  
  ParameterList() {
  }
  
  std::shared_ptr<Parameter> at(size_t n) {
    return get(n);
  }

  std::shared_ptr<Parameter> getParameter(int n) {
    return get(n);
  }

  std::shared_ptr<Parameter> getParameter(const std::string &name)
  {
    size_t nLists = size();
    for (size_t n = 0; n < nLists; n++) {
      std::shared_ptr<Parameter> param = at(n);
      if (uHTTP::StringEquals(name, param->getName()) == true)
        return param;
    }
    return std::shared_ptr<Parameter>(NULL);
  }

  bool getParameterValue(const std::string &name, std::string *value)
  {
    std::shared_ptr<Parameter> param = getParameter(name);
    if (param == std::shared_ptr<Parameter>(NULL))
      return false;
    *value = param->getValue();
    return true;
  }
};

}

#endif
