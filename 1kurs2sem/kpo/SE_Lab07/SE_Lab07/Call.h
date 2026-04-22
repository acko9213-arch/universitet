#pragma once
namespace Call
{
	int _cdecl cd(int x, int b, int c);
	int _stdcall stdc(int& a, int b, int c);
	int _fastcall fastc(int a, int b, int c, int d);
 }