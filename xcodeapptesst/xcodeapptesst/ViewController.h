//
//  ViewController.h
//  xcodeapptesst
//
//  Created by Đỗ Thành on 02/12/2024.
//
#import <UIKit/UIKit.h>

@interface ViewController : UIViewController

@property (weak, nonatomic) IBOutlet UILabel *apiLabel;
@property (weak, nonatomic) IBOutlet UILabel *ctdoTechLabel;
- (IBAction)runButtonTapped:(UIButton *)sender;

@end
