//
// skulk@ioc.ninja
//
#pragma once



#include <Windows.h>
#include <IPHlpApi.h>

#include "xDynamicModule.h"



#ifndef X_USE_OBFUSCATED_API
	#pragma comment (lib, "Iphlpapi")
	#pragma comment (lib, "Kernel32")
	#pragma comment (lib, "Ole32")
	#pragma comment (lib, "OleAut32")
	#pragma comment (lib, "User32")
	#pragma comment (lib, "Ws2_32")	
#endif



class xOsApi
{
private:
	xOsApi()
	{
	}

public:
	static xOsApi& GetOsApi()
	{
		static xOsApi s_osApi;

		return s_osApi;
	}

public:
	// Advapi32
	X_DYNAMIC_MODULE_BEGIN(Advapi32, X_OBFUSCATED_STRING_W(L"Advapi32.dll"))
		X_DYNAMIC_MODULE_FUNCTION_1(LONG, RegCloseKey, HKEY)
#ifdef _UNICODE
		// UNICODE API's
		X_DYNAMIC_MODULE_FUNCTION_3(LONG, RegOpenKeyW, HKEY, LPCWSTR, PHKEY)
		X_DYNAMIC_MODULE_FUNCTION_5(LONG, RegOpenKeyExW, HKEY, LPCWSTR, DWORD, REGSAM, PHKEY)
		X_DYNAMIC_MODULE_FUNCTION_6(LONG, RegSetValueExW, HKEY, LPCWSTR, DWORD, DWORD, const uint8_t*, DWORD)
#else
		// ANSI API's
		X_DYNAMIC_MODULE_FUNCTION_3(LONG, RegOpenKeyA, HKEY, LPCSTR, PHKEY)
		X_DYNAMIC_MODULE_FUNCTION_5(LONG, RegOpenKeyExA, HKEY, LPCSTR, DWORD, REGSAM, PHKEY)
		X_DYNAMIC_MODULE_FUNCTION_6(LONG, RegSetValueExA, HKEY, LPCWSTR, DWORD, DWORD, const uint8_t*, DWORD)
#endif
	X_DYNAMIC_MODULE_END(Advapi32)
		
	// Iphlpapi
	X_DYNAMIC_MODULE_BEGIN(Iphlpapi, X_OBFUSCATED_STRING_W(L"Iphlpapi.dll"))
		X_DYNAMIC_MODULE_FUNCTION_1(BOOL, IcmpCloseHandle, HANDLE)
		X_DYNAMIC_MODULE_FUNCTION_0(HANDLE, IcmpCreateFile)
		X_DYNAMIC_MODULE_FUNCTION_8(DWORD, IcmpSendEcho, HANDLE, IPAddr, LPVOID, WORD, PIP_OPTION_INFORMATION, LPVOID, DWORD, DWORD)
	X_DYNAMIC_MODULE_END(Iphlpapi)

	// Kernel32
	X_DYNAMIC_MODULE_BEGIN(Kernel32, X_OBFUSCATED_STRING_W(L"Kernel32.dll"))
		X_DYNAMIC_MODULE_FUNCTION_2(PVOID, AddVectoredExceptionHandler, ULONG, PVECTORED_EXCEPTION_HANDLER)
		X_DYNAMIC_MODULE_FUNCTION_1(BOOL, CloseHandle, HANDLE)
		X_DYNAMIC_MODULE_FUNCTION_6(HANDLE, CreateThread, LPSECURITY_ATTRIBUTES, SIZE_T, LPTHREAD_START_ROUTINE, LPVOID, DWORD, LPDWORD)
		X_DYNAMIC_MODULE_FUNCTION_1(void, DeleteCriticalSection, LPCRITICAL_SECTION)
		X_DYNAMIC_MODULE_FUNCTION_1(void, EnterCriticalSection, LPCRITICAL_SECTION)
		X_DYNAMIC_MODULE_FUNCTION_1(void, ExitProcess, DWORD)
		X_DYNAMIC_MODULE_FUNCTION_0(HANDLE, GetCurrentProcess)
		X_DYNAMIC_MODULE_FUNCTION_0(DWORD, GetLastError)
		X_DYNAMIC_MODULE_FUNCTION_1(void, GetNativeSystemInfo, LPSYSTEM_INFO)
		X_DYNAMIC_MODULE_FUNCTION_0(HANDLE, GetProcessHeap)
		X_DYNAMIC_MODULE_FUNCTION_0(LCID, GetThreadLocale)
		X_DYNAMIC_MODULE_FUNCTION_0(DWORD, GetTickCount)
		X_DYNAMIC_MODULE_FUNCTION_3(LPVOID, HeapAlloc, HANDLE, DWORD, SIZE_T)
		X_DYNAMIC_MODULE_FUNCTION_3(BOOL, HeapFree, HANDLE, DWORD, LPVOID)
		X_DYNAMIC_MODULE_FUNCTION_1(void, InitializeCriticalSection, LPCRITICAL_SECTION)
		X_DYNAMIC_MODULE_FUNCTION_2(BOOL, IsBadReadPtr, const VOID*, UINT_PTR)
		X_DYNAMIC_MODULE_FUNCTION_1(void, LeaveCriticalSection, LPCRITICAL_SECTION)
		X_DYNAMIC_MODULE_FUNCTION_2(HGLOBAL, LoadResource, HMODULE, HRSRC)
		X_DYNAMIC_MODULE_FUNCTION_1(ULONG, RemoveVectoredExceptionHandler, PVOID)
		X_DYNAMIC_MODULE_FUNCTION_2(BOOL, SetPriorityClass, HANDLE, DWORD)
		X_DYNAMIC_MODULE_FUNCTION_2(BOOL, SetThreadPriority, HANDLE, DWORD)
		X_DYNAMIC_MODULE_FUNCTION_1(void, Sleep, DWORD)
		X_DYNAMIC_MODULE_FUNCTION_1(void, SetLastError, DWORD)
		X_DYNAMIC_MODULE_FUNCTION_4(LPVOID, VirtualAlloc, LPVOID, SIZE_T, DWORD, DWORD)
		X_DYNAMIC_MODULE_FUNCTION_3(BOOL, VirtualFree, LPVOID, SIZE_T, DWORD)
		X_DYNAMIC_MODULE_FUNCTION_4(BOOL, VirtualProtect, LPVOID, SIZE_T, DWORD, PDWORD)
		X_DYNAMIC_MODULE_FUNCTION_2(DWORD, WaitForSingleObject, HANDLE, DWORD)
		X_DYNAMIC_MODULE_FUNCTION_5(BOOL, WriteFile, HANDLE, LPCVOID, DWORD, LPDWORD, LPOVERLAPPED)
#ifdef _UNICODE
		// UNICODE API's
		X_DYNAMIC_MODULE_FUNCTION_7(HANDLE, CreateFileW, LPCWSTR, DWORD, DWORD, LPSECURITY_ATTRIBUTES, DWORD, DWORD, HANDLE)
		X_DYNAMIC_MODULE_FUNCTION_3(HRSRC, FindResourceW, HMODULE, LPCWSTR, LPCWSTR)
		X_DYNAMIC_MODULE_FUNCTION_3(BOOL, GetComputerNameExW, COMPUTER_NAME_FORMAT, LPWSTR, LPDWORD)
		X_DYNAMIC_MODULE_FUNCTION_2(DWORD, GetCurrentDirectoryW, DWORD, LPWSTR)
		X_DYNAMIC_MODULE_FUNCTION_3(DWORD, GetModuleFileNameW, HMODULE, LPWSTR, DWORD)
		X_DYNAMIC_MODULE_FUNCTION_1(HMODULE, GetModuleHandleW, LPCWSTR)
		X_DYNAMIC_MODULE_FUNCTION_1(void, OutputDebugStringW, LPCWSTR)
#else
		// ANSI API's
		X_DYNAMIC_MODULE_FUNCTION_7(HANDLE, CreateFileA, LPCTSTR, DWORD, DWORD, LPSECURITY_ATTRIBUTES, DWORD, DWORD, HANDLE)
		X_DYNAMIC_MODULE_FUNCTION_3(HRSRC, FindResourceA, HMODULE, LPCSTR, LPCSTR)
		X_DYNAMIC_MODULE_FUNCTION_3(BOOL, GetComputerNameExA, COMPUTER_NAME_FORMAT, LPSTR, LPDWORD)
		X_DYNAMIC_MODULE_FUNCTION_2(DWORD, GetCurrentDirectoryA, DWORD, LPSTR)
		X_DYNAMIC_MODULE_FUNCTION_3(DWORD, GetModuleFileNameA, HMODULE, LPSTR, DWORD)
		X_DYNAMIC_MODULE_FUNCTION_1(HMODULE, GetModuleHandleA, LPCSTR)
		X_DYNAMIC_MODULE_FUNCTION_1(void, OutputDebugStringA, LPCSTR)
#endif
	X_DYNAMIC_MODULE_END(Kernel32)
		
		// Ole32
	X_DYNAMIC_MODULE_BEGIN(Ole32, X_OBFUSCATED_STRING_W(L"Ole32.dll"))
		X_DYNAMIC_MODULE_FUNCTION_5(HRESULT, CoCreateInstance, REFCLSID, LPUNKNOWN, DWORD, REFIID, LPVOID*)
		X_DYNAMIC_MODULE_FUNCTION_1(HRESULT, CoInitialize, LPVOID)
		X_DYNAMIC_MODULE_FUNCTION_0(void, CoUninitialize)
	X_DYNAMIC_MODULE_END(Ole32)

	// OleAut32
	X_DYNAMIC_MODULE_BEGIN(OleAut32, X_OBFUSCATED_STRING_W(L"OleAut32.dll"))
		X_DYNAMIC_MODULE_FUNCTION_1(BSTR, SysAllocString, const OLECHAR*)
		X_DYNAMIC_MODULE_FUNCTION_1(void, SysFreeString, BSTR)
	X_DYNAMIC_MODULE_END(OleAut32)
		
	// User32
	X_DYNAMIC_MODULE_BEGIN(User32, X_OBFUSCATED_STRING_W(L"User32.dll"))
		X_DYNAMIC_MODULE_FUNCTION_1(BOOL, DestroyWindow, HWND)
		X_DYNAMIC_MODULE_FUNCTION_1(void, PostQuitMessage, int)
		X_DYNAMIC_MODULE_FUNCTION_1(BOOL, TranslateMessage, LPMSG)
#ifdef _UNICODE
		// UNICODE API's
		X_DYNAMIC_MODULE_FUNCTION_12(HWND, CreateWindowExW, DWORD, LPCWSTR, LPCWSTR, DWORD, int, int, int, int, HWND, HMENU, HINSTANCE, LPVOID)
		X_DYNAMIC_MODULE_FUNCTION_4(LRESULT, DefWindowProcW, HWND, UINT, WPARAM, LPARAM)
		X_DYNAMIC_MODULE_FUNCTION_1(LRESULT, DispatchMessageW, LPMSG)
		X_DYNAMIC_MODULE_FUNCTION_4(BOOL, GetMessageW, LPMSG, HWND, UINT, UINT)
		X_DYNAMIC_MODULE_FUNCTION_1(ATOM, RegisterClassExW, const WNDCLASSEX*)
#else
		// ANSI API's
		X_DYNAMIC_MODULE_FUNCTION_12(LRESULT, CreateWindowExA, DWORD, LPCSTR, LPCSTR, DWORD, int, int, int, int, HWND, HMENU, HINSTANCE, LPVOID)
		X_DYNAMIC_MODULE_FUNCTION_4(LRESULT, DefWindowProcA, HWND, UINT, WPARAM, LPARAM)
		X_DYNAMIC_MODULE_FUNCTION_1(LRESULT, DispatchMessageA, LPMSG)
		X_DYNAMIC_MODULE_FUNCTION_4(BOOL, GetMessageA, LPMSG, HWND, UINT, UINT)
		X_DYNAMIC_MODULE_FUNCTION_1(ATOM, RegisterClassExA, const WNDCLASSEX*)
#endif
		X_DYNAMIC_MODULE_END(User32)
		
		// Ws2_32
	X_DYNAMIC_MODULE_BEGIN(Ws2_32, X_OBFUSCATED_STRING_W(L"Ws2_32.dll"))
		X_DYNAMIC_MODULE_FUNCTION_1(int, closesocket, SOCKET)
		X_DYNAMIC_MODULE_FUNCTION_3(int, connect, SOCKET, const struct sockaddr*, int)
		X_DYNAMIC_MODULE_FUNCTION_1(u_short, htons, u_short)
		X_DYNAMIC_MODULE_FUNCTION_1(unsigned long, inet_addr, const char*)
		X_DYNAMIC_MODULE_FUNCTION_3(int, ioctlsocket, SOCKET, long, u_long*)
		X_DYNAMIC_MODULE_FUNCTION_5(int, select, int, fd_set*, fd_set*, fd_set*, const struct timeval*)
		X_DYNAMIC_MODULE_FUNCTION_3(SOCKET, socket, int, int, int)
		X_DYNAMIC_MODULE_FUNCTION_0(int, WSACleanup)
		X_DYNAMIC_MODULE_FUNCTION_2(int, WSAStartup, WORD, LPWSADATA)
	X_DYNAMIC_MODULE_END(Ws2_32)
};

static xOsApi& xGetOsApi() {return xOsApi::GetOsApi();}



#ifdef X_USE_OBFUSCATED_API
	#define X_ADVAPI32_CALL(__Name)	xGetOsApi().GetAdvapi32().##__Name
	#define X_IPHLPAPI_CALL(__Name)	xGetOsApi().GetIphlpapi().##__Name
	#define X_KERNEL32_CALL(__Name)	xGetOsApi().GetKernel32().##__Name
	#define X_OLE32_CALL(__Name)	xGetOsApi().GetOle32().##__Name
	#define X_OLEAUT32_CALL(__Name)	xGetOsApi().GetOleAut32().##__Name
	#define X_USER32_CALL(__Name)	xGetOsApi().GetUser32().##__Name
	#define X_WS2_32_CALL(__Name)	xGetOsApi().GetWs2_32().##__Name
#else
	#define X_ADVAPI32_CALL(__Name)	__Name
	#define X_IPHLPAPI_CALL(__Name)	__Name
	#define X_KERNEL32_CALL(__Name)	__Name
	#define X_OLE32_CALL(__Name)	__Name
	#define X_OLEAUT32_CALL(__Name)	__Name
	#define X_USER32_CALL(__Name)	__Name
	#define X_WS2_32_CALL(__Name)	__Name
#endif