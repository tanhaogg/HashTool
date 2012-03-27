//
//  AppDelegate.h
//  DragHash
//
//  Created by Hao Tan on 12-3-26.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "THDragView.h"
#import "THWebUtility.h"

@interface AppDelegate : NSObject <NSApplicationDelegate,THDragViewDelegate>
{
    NSWindow *_window;
    NSString *filePath;
    IBOutlet NSPopUpButton *kindButton;
    IBOutlet NSTextField   *hashField;
    IBOutlet NSTextField   *titleField;
}

@property (strong) IBOutlet NSWindow *window;

- (IBAction)kindClick:(id)sender;
- (IBAction)copyClick:(id)sender;
- (IBAction)aboutClick:(id)sender;

@end
