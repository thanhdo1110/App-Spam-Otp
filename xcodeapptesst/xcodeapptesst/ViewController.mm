//
//  ViewController.m
//  xcodeapptesst
//
//  Created by Đỗ Thành on 02/12/2024.
//

#import "ViewController.h"
#import "mahoa.h"
#import "MBProgressHUD.h"
#import <WebKit/WebKit.h>
@interface ViewController () <UITextFieldDelegate>
@property (strong, nonatomic) UILabel *brandLabel;
@property (strong, nonatomic) UITextField *phoneTextField;
@property (strong, nonatomic) UIButton *eyeButton;
@property (strong, nonatomic) UIButton *runButton;
@property (strong, nonatomic) UILabel *footerLabel;
@property (strong, nonatomic) UISwitch *loopSwitch;
@property (strong, nonatomic) UILabel *successLabel;
@property (strong, nonatomic) UITextView *logTextView;
@property (nonatomic, strong) MBProgressHUD *currentHUD;
@property (nonatomic) BOOL isPhoneVisible;
@property (nonatomic) BOOL isLooping;
@property (nonatomic) NSTimer *loopTimer;
@end

@implementation ViewController

- (void)viewDidLoad {

    [super viewDidLoad];

    // Thiết lập nền màu đen
    self.view.backgroundColor = [UIColor blackColor];
  //  [self openURL];
    // Tạo UILabel cho tên thương hiệu
    self.brandLabel = [[UILabel alloc] initWithFrame:CGRectMake(20, 50, self.view.frame.size.width - 40, 40)];
    self.brandLabel.text = NSSENCRYPT("CTDOTECH");
    self.brandLabel.textAlignment = NSTextAlignmentCenter;
    self.brandLabel.font = [UIFont boldSystemFontOfSize:24];
    self.brandLabel.textColor = [UIColor whiteColor]; // Đặt màu chữ cho nổi bật trên nền đen
    [self.view addSubview:self.brandLabel];
    

    
    // Tạo UITextField cho nhập số điện thoại
    self.phoneTextField = [[UITextField alloc] initWithFrame:CGRectMake(20, 120, self.view.frame.size.width - 40, 50)];
    self.phoneTextField.borderStyle = UITextBorderStyleNone; // Không có viền mặc định
    self.phoneTextField.backgroundColor = [UIColor whiteColor]; // Nền trắng
    self.phoneTextField.textColor = [UIColor blackColor]; // Màu chữ đen
    self.phoneTextField.layer.cornerRadius = 10; // Bo góc
    self.phoneTextField.layer.masksToBounds = YES; // Đảm bảo bo góc đúng
    self.phoneTextField.font = [UIFont systemFontOfSize:16]; // Cỡ chữ phù hợp
    self.phoneTextField.textAlignment = NSTextAlignmentCenter; // Canh giữa nội dung
    self.phoneTextField.delegate = self; // Thiết lập delegate cho text field
    self.phoneTextField.keyboardType = UIKeyboardTypeNumberPad; // Hiển thị bàn phím số
    self.phoneTextField.secureTextEntry = YES;
    self.isPhoneVisible = NO; // Ban đầu số điện thoại sẽ bị ẩn

    // Đặt màu chữ placeholder
    UIColor *placeholderColor = [UIColor colorWithRed:0.2 green:0.2 blue:0.2 alpha:0.6]; // Màu chữ placeholder
    NSDictionary *placeholderAttributes = @{NSForegroundColorAttributeName: placeholderColor};
    NSAttributedString *attributedPlaceholder = [[NSAttributedString alloc] initWithString:NSSENCRYPT("Nhập số điện thoại") attributes:placeholderAttributes];
    self.phoneTextField.attributedPlaceholder = attributedPlaceholder;

    [self.view addSubview:self.phoneTextField];

    // Thiết lập viền mặc định là đỏ (khi chưa nhập số)
    self.phoneTextField.layer.borderColor = [UIColor redColor].CGColor; // Viền màu đỏ
    self.phoneTextField.layer.borderWidth = 1.0;

    // Thêm observer để theo dõi sự thay đổi của textField
    [self.phoneTextField addTarget:self action:@selector(phoneNumberChanged:) forControlEvents:UIControlEventEditingChanged];

    // Thêm icon "mắt" cho việc ẩn/hiện số điện thoại
    self.eyeButton = [UIButton buttonWithType:UIButtonTypeSystem];
    CGFloat eyeButtonWidth = 40;
    self.eyeButton.frame = CGRectMake(self.phoneTextField.frame.size.width - eyeButtonWidth - 10,
                                      (self.phoneTextField.frame.size.height - eyeButtonWidth) / 2, // Căn giữa theo chiều dọc
                                      eyeButtonWidth, eyeButtonWidth);
    [self.eyeButton setImage:[UIImage systemImageNamed:@"eye"] forState:UIControlStateNormal];
    [self.eyeButton addTarget:self action:@selector(eyeButtonTapped:) forControlEvents:UIControlEventTouchUpInside];
    [self.phoneTextField addSubview:self.eyeButton];

    // Thiết lập viền mặc định là xanh biển
    self.phoneTextField.layer.borderColor = [UIColor blueColor].CGColor; // Viền màu xanh biển
    self.phoneTextField.layer.borderWidth = 1.0;

    // Thêm observer để theo dõi sự thay đổi của textField
    [self.phoneTextField addTarget:self action:@selector(phoneNumberChanged:) forControlEvents:UIControlEventEditingChanged];
    
    // Tạo UIButton cho nút Run
    self.runButton = [UIButton buttonWithType:UIButtonTypeSystem];
    self.runButton.frame = CGRectMake(20, 180, self.view.frame.size.width - 120, 40);
    [self.runButton setTitle:@"Run" forState:UIControlStateNormal];
    [self.runButton setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal]; // Đặt màu chữ cho nút
    self.runButton.backgroundColor = [UIColor colorWithRed:0.2 green:0.4 blue:0.8 alpha:1.0]; // Đặt màu nền cho nút
    self.runButton.layer.cornerRadius = 8; // Bo tròn góc nút
    [self.runButton addTarget:self action:@selector(runButtonTapped:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:self.runButton];
    
    // Tạo UISwitch cho nút gạt
    self.loopSwitch = [[UISwitch alloc] initWithFrame:CGRectMake(self.view.frame.size.width - 80, 180, 60, 40)];
    [self.loopSwitch addTarget:self action:@selector(loopSwitchChanged:) forControlEvents:UIControlEventValueChanged];
    [self.view addSubview:self.loopSwitch];
    
    // Tạo UILabel cho chân app
    self.footerLabel = [[UILabel alloc] initWithFrame:CGRectMake(20, self.view.frame.size.height - 80, self.view.frame.size.width - 40, 40)];
    self.footerLabel.text = NSSENCRYPT("@dothanh1110");
    self.footerLabel.textAlignment = NSTextAlignmentCenter;
    self.footerLabel.textColor = [UIColor whiteColor]; // Đặt màu chữ cho nổi bật trên nền đen
    self.footerLabel.userInteractionEnabled = YES;
    UITapGestureRecognizer *tapGesture = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(footerLabelTapped:)];
    [self.footerLabel addGestureRecognizer:tapGesture];
    [self.view addSubview:self.footerLabel];
    
    // Tạo UIView bao bọc để chứa UILabel
    UIView *containerView = [[UIView alloc] initWithFrame:CGRectMake(20, 240, self.view.frame.size.width - 40, 80)];
    containerView.backgroundColor = [UIColor colorWithRed:0.0 green:0.5 blue:1.0 alpha:0.7]; // Màu nền xanh biển
    containerView.layer.borderColor = [UIColor blueColor].CGColor; // Màu viền
    containerView.layer.borderWidth = 3.0; // Độ dày viền
    containerView.layer.cornerRadius = 8; // Bo góc
    containerView.clipsToBounds = YES; // Nội dung không vượt ra ngoài viền

    // Tạo UILabel
    self.successLabel = [[UILabel alloc] initWithFrame:CGRectInset(containerView.bounds, 10, 10)]; // Tạo padding 10px
    self.successLabel.textAlignment = NSTextAlignmentLeft; // Đặt căn chỉnh về lề trái
 //   self.successLabel.textAlignment = NSTextAlignmentCenter; // Đặt căn chỉnh về giữa
 //   self.successLabel.textAlignment = NSTextAlignmentRight; // Đặt căn chỉnh về lề phải
    self.successLabel.textColor = [UIColor whiteColor];
    self.successLabel.backgroundColor = [UIColor clearColor]; // Làm nền UILabel trong suốt
    self.successLabel.numberOfLines = 0;
    self.successLabel.lineBreakMode = NSLineBreakByWordWrapping;

    // Thiết lập text
    NSString *text = NSSENCRYPT("App hoàn toàn free nếu bạn mua nó tức là bạn đã bị lừa\n"
                      "Tuyên bố miễn trừ trách nhiệm\n"
                      "------------------------------\n"
                      "Mô tả.\n"
                      "• Nhập sđt vào ô nhập sđt\n"
                      "• Định dạng sđt 0xx.xxxxxxx\n"
                      "• Nút Run sẽ spam 1 lần\n"
                      "• Nút Gạt sẽ spam vô hạn đến khi tắt\n"
                      "------------------------------\n"
                      "Donate.\n"
                      "STK: 9999991110 || MbBank\n"
                                "- Phiên bản: v0.2 -\n"
                      "Thêm Api 36.");
    NSMutableAttributedString *attributedString = [[NSMutableAttributedString alloc] initWithString:text];
    [attributedString addAttribute:NSFontAttributeName value:[UIFont systemFontOfSize:14] range:NSMakeRange(0, attributedString.length)];

    self.successLabel.attributedText = attributedString;

    // Tính toán kích thước cần thiết cho successLabel
    CGSize maxSize = CGSizeMake(containerView.frame.size.width - 20, CGFLOAT_MAX);
    CGSize requiredSize = [self.successLabel sizeThatFits:maxSize];
    self.successLabel.frame = CGRectMake(10, 10, requiredSize.width, requiredSize.height);

    // Điều chỉnh chiều cao của containerView
    CGRect containerFrame = containerView.frame;
    containerFrame.size.height = requiredSize.height + 20; // Cộng thêm padding trên và dưới
    containerView.frame = containerFrame;


    // Giảm kích thước chữ
    [attributedString addAttribute:NSFontAttributeName value:[UIFont systemFontOfSize:14] range:NSMakeRange(0, attributedString.length)];
    self.successLabel.attributedText = attributedString;

    // Tự động điều chỉnh kích thước
    [self.successLabel sizeToFit];
    self.successLabel.frame = CGRectMake(10, 10, containerView.frame.size.width - 20, self.successLabel.frame.size.height);

    // Thêm UILabel vào containerView
    [containerView addSubview:self.successLabel];


    // Thêm containerView vào view chính
    [self.view addSubview:containerView];

    
    // Thêm UITextView để hiển thị log
    self.logTextView = [[UITextView alloc] initWithFrame:CGRectMake(20, containerView.frame.origin.y + containerView.frame.size.height + 20, self.view.frame.size.width - 40, 100)];
    self.logTextView.backgroundColor = [UIColor colorWithWhite:0.1 alpha:0.9]; // Nền tối
    self.logTextView.textColor = [UIColor whiteColor]; // Màu chữ trắng
    self.logTextView.font = [UIFont systemFontOfSize:12]; // Cỡ chữ nhỏ
    self.logTextView.editable = NO; // Không cho phép chỉnh sửa
    self.logTextView.layer.cornerRadius = 8; // Bo góc
    self.logTextView.layer.borderColor = [UIColor grayColor].CGColor; // Viền màu xám
    self.logTextView.layer.borderWidth = 1.0; // Độ dày viền
    [self.view addSubview:self.logTextView];

    // Thêm gesture recognizer để ẩn bàn phím khi chạm vào phần khác của màn hình
    UITapGestureRecognizer *tapGestureRecognizer = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(dismissKeyboard:)];
    [self.view addGestureRecognizer:tapGestureRecognizer];
}

//hàm mở url
- (void)openURL {
    NSURL *url = [NSURL URLWithString:NSSENCRYPT("https://thongoakardusti.net/4/8602224")];
    if ([[UIApplication sharedApplication] canOpenURL:url]) {
        [[UIApplication sharedApplication] openURL:url options:@{} completionHandler:nil];
    } else {
        NSLog(@"Không thể mở URL: %@", url);
    }
}

// hàm hiển thị log
- (void)logMessage:(NSString *)message {
    dispatch_async(dispatch_get_main_queue(), ^{
        self.logTextView.text = [self.logTextView.text stringByAppendingFormat:@"%@\n", message];
        [self.logTextView scrollRangeToVisible:NSMakeRange(self.logTextView.text.length, 0)];
    });
}

- (void)phoneNumberChanged:(UITextField *)textField {
    NSString *phoneNumber = textField.text;
    
    // Kiểm tra xem số điện thoại có đúng định dạng chưa
    if (phoneNumber.length == 0) {
        // Nếu chưa nhập số, viền sẽ là đỏ
        self.phoneTextField.layer.borderColor = [UIColor redColor].CGColor; // Viền đỏ
    } else if (phoneNumber.length < 10) {
        // Nếu đang nhập mà chưa đủ 10 số, viền sẽ là xanh biển
        self.phoneTextField.layer.borderColor = [UIColor blueColor].CGColor; // Viền xanh biển
    } else if (phoneNumber.length == 10 && [phoneNumber hasPrefix:@"0"]) {
        // Nếu đã đủ 10 số và có số 0 ở đầu, viền sẽ là xanh lá
        self.phoneTextField.layer.borderColor = [UIColor greenColor].CGColor; // Viền xanh lá
    } else {
        // Nếu không đúng định dạng (số điện thoại không bắt đầu bằng 0 hoặc không đủ 10 số)
        self.phoneTextField.layer.borderColor = [UIColor redColor].CGColor; // Viền đỏ
    }
}




- (void)eyeButtonTapped:(id)sender {
    self.isPhoneVisible = !self.isPhoneVisible;
    self.phoneTextField.secureTextEntry = !self.isPhoneVisible;
    [self.eyeButton setImage:[UIImage systemImageNamed:self.isPhoneVisible ? @"eye.slash" : @"eye"] forState:UIControlStateNormal];
}


- (void)loopSwitchChanged:(id)sender {
    self.isLooping = self.loopSwitch.isOn;
    if (self.isLooping) {
        [self showHUDWithMessage:@"Đã Bắt Đầu Spam" duration:1.5];
        self.loopTimer = [NSTimer scheduledTimerWithTimeInterval:2.0 target:self selector:@selector(sendOTPAndNewOTPRequests) userInfo:nil repeats:YES];
    } else {
        [self.loopTimer invalidate];
        self.loopTimer = nil;
        [self showHUDWithMessage:@"Bắt Đầu Dừng Hết Tiến Trình" duration:1.0];
    }
}
- (void)sendOTPAndNewOTPRequests {
    
    [self tv360];
    [self viettel_login_dang_nhap];
    [self viettel_tao_tai_khoan];
    [self sapo_tao_acc];
    [self modcha];
    [self vieon];
    [self fptshop];
    [self fptshop1];
    [self galaxyplay];
    [self Shine30];
    [self Shine30_test];
    [self cathay];
    [self dominos];
    [self batdongsan];
    [self fahase];
    [self shopiness];
    [self viettelpost];
    [self bibabo];
    [self owen];
    [self pnj];
    [self f88];
    [self heyu];
    [self thecoffee];
    [self dienmayxanh];
    [self kingfoodmart];
    [self ghn];
    [self lottemart];
    [self vayvnd];
    [self vato];
    [self nhathuoclongchau];
    [self vinamilk];
    [self glxplay];
    [self shopee];
    [self watsons];
    [self tokyolife];
    [self go2joy];
}

- (void)runButtonTapped:(id)sender {
    self.currentHUD = [MBProgressHUD showHUDAddedTo:self.view animated:YES];
    self.currentHUD.mode = MBProgressHUDModeIndeterminate;
    self.currentHUD.label.text = @"Đã Bắt Đầu Spam";
    
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1.0 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        self.currentHUD.label.text = @"Đang Gửi Yêu Cầu Spam";
        
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
            // quảng cáo
         
            [self tv360];
            [self viettel_login_dang_nhap];
            [self viettel_tao_tai_khoan];
            [self sapo_tao_acc];
            [self modcha];
            [self vieon];
            [self fptshop];
            [self fptshop1];
            [self galaxyplay];
            [self Shine30];
            [self Shine30_test];
            [self cathay];
            [self dominos];
            [self batdongsan];
            [self fahase];
            [self shopiness];
            [self viettelpost];
            [self bibabo];
            [self owen];
            [self pnj];
            [self f88];
            [self heyu];
            [self thecoffee];
            [self dienmayxanh];
            [self kingfoodmart];
            [self ghn];
            [self lottemart];
            [self vayvnd];
            [self vato];
            [self nhathuoclongchau];
            [self vinamilk];
            [self glxplay];
            [self shopee];
            [self watsons];
            [self tokyolife];
            [self go2joy];
            
            dispatch_async(dispatch_get_main_queue(), ^{
                self.currentHUD.label.text = @"Đã Gửi Yêu Cầu Spam Xong";
                dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1.5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
                    [self.currentHUD hideAnimated:YES];
                });
            });
        });
    });
}
- (void)footerLabelTapped:(id)sender {
    NSURL *url = [NSURL URLWithString:NSSENCRYPT("https://t.me/dothanh1110")];
    [[UIApplication sharedApplication] openURL:url options:@{} completionHandler:nil];
}

#import "apiotp.h"

#pragma mark - UITextFieldDelegate

- (BOOL)textFieldShouldReturn:(UITextField *)textField {
    [textField resignFirstResponder]; // Ẩn bàn phím khi nhấn nút return
    return YES;
}

#pragma mark - Dismiss Keyboard

- (void)dismissKeyboard:(UITapGestureRecognizer *)gesture {
    [self.view endEditing:YES]; // Ẩn bàn phím khi người dùng chạm vào phần khác của màn hình
}

#pragma mark - MBProgressHUD

- (void)showHUDWithMessage:(NSString *)message duration:(NSTimeInterval)duration {
    MBProgressHUD *hud = [MBProgressHUD showHUDAddedTo:self.view animated:YES];
    hud.mode = MBProgressHUDModeIndeterminate;
    hud.label.text = message;
    
    // Tự động ẩn sau khoảng thời gian đã định
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(duration * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        [hud hideAnimated:YES];
    });
}

- (void)showHUDWithMessage:(NSString *)message {
    MBProgressHUD *hud = [MBProgressHUD showHUDAddedTo:self.view animated:YES];
    hud.mode = MBProgressHUDModeIndeterminate;
    hud.label.text = message;
}

- (void)hideHUD {
    [MBProgressHUD hideHUDForView:self.view animated:YES];
}

@end
