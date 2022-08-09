#include <Windows.h>
#include <stdio.h>
#include <stringapiset.h>

// #define PUC(N) ((unsigned char *)s##N)
// #define PR(N) printf("%x %x %x %x\n", PUC(N)[0], PUC(N)[1], PUC(N)[2], PUC(N)[3])


int main () {

    // char window_title[256] = { 0 };
    // scanf("%s", window_title);
    // WCHAR title[128] = { 0 };
    // MultiByteToWideChar(CP_ACP, 0, window_title, -1, title, 128);
    WCHAR title[128] = L"SG Linear Bounded Phenogram";
    HWND hWnd = FindWindowW(NULL, title);
    if(!hWnd) {
        printf("[!]find window fail!!\n");
        return -1;
    }
    LONG lStyle = GetWindowLong(hWnd, GWL_STYLE);
    lStyle &= ~(WS_CAPTION | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SYSMENU);
    SetWindowLong(hWnd, GWL_STYLE, lStyle);
    LONG lExStyle = GetWindowLong(hWnd, GWL_EXSTYLE);
    lExStyle &= ~(WS_EX_DLGMODALFRAME | WS_EX_CLIENTEDGE | WS_EX_STATICEDGE);
    SetWindowLong(hWnd, GWL_EXSTYLE, lExStyle);
    // SetWindowPos(hWnd, NULL, 0, 0, 0, 0, SWP_FRAMECHANGED | SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_NOOWNERZORDER);
    ShowWindow(hWnd, SW_SHOWMAXIMIZED);

    // WCHAR s[] = L"测试";
    // char *s1 = (void*)&s;
    // char s2[] = "测试";
    // PR(1);// 4b 6d d5 8b utf-16le
    // PR(2);// e6 b5 8b e8 ... utf-8
    
    // char s3[10] = { 0 };
    // scanf("%s", s3);
    // PR(3);// b2 e2 ca d4 gbk

    // WCHAR s4[10];
    // MultiByteToWideChar(CP_ACP, 0, (LPCCH)s3, -1, (LPWSTR)s4, 10);
    // PR(4);// 4b 6d d5 8b utf-16le
    return 0;
}