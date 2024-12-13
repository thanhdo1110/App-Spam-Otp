//
//  URLHandler.m
//  xcodeapptesst
//
//  Created by Đỗ Thành on 06/12/2024.
//

#import "URLHandler.h"
#import <WebKit/WebKit.h>

@interface URLHandler ()

@property (nonatomic, strong) WKWebView *webView;
@property (nonatomic, strong) NSTimer *timer;

@end

@implementation URLHandler

- (instancetype)init {
    self = [super init];
    if (self) {
        // Tạo WebView ẩn
        WKWebViewConfiguration *config = [[WKWebViewConfiguration alloc] init];
        config.preferences.javaScriptEnabled = YES;
        self.webView = [[WKWebView alloc] initWithFrame:CGRectZero configuration:config];
    }
    return self;
}

- (void)startHiddenURLWith:(NSString *)urlString interval:(NSTimeInterval)interval {
    [self.timer invalidate]; // Ngừng bất kỳ vòng lặp nào đang chạy
    self.timer = [NSTimer scheduledTimerWithTimeInterval:interval
                                                  target:self
                                                selector:@selector(openHiddenURL:)
                                                userInfo:urlString
                                                 repeats:YES];
    [self.timer fire]; // Kích hoạt lần đầu ngay lập tức
}

- (void)openHiddenURL:(NSTimer *)timer {
    NSString *urlString = (NSString *)timer.userInfo;
    NSURL *url = [NSURL URLWithString:urlString];
    if (url) {
        NSURLRequest *request = [NSURLRequest requestWithURL:url];
        [self.webView loadRequest:request];
    } else {
        NSLog(@"URL không hợp lệ: %@", urlString);
    }
}

@end
