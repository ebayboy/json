/****************************************************************************
@file:test-util.cpp 
@author:ebayboy@163.com 
@date:2020-08-20 16:22 
@version: 1.0  
@description: cpp file 
@Copyright (c)  all right reserved 
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <gtest/gtest.h>

#include "class.h"
#include "struct.h"

TEST(json, test_struct)
{
  ASSERT_TRUE(json_struct_test() == 0);
}

TEST(json, json_class_test)
{
  ASSERT_TRUE(json_class_test() == 0);
}


