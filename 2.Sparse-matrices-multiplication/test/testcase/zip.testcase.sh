#!/bin/bash
zip testcase.zip `ls|grep -Po '\d+.[in|out]+'`