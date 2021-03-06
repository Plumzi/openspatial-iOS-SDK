//
//  OpenSpatialDecoder.h
//  OpenSpatial.framework
//
//  Copyright (c) 2015 Nod Labs. All rights reserved.
//

/*!
 *  This class decodes an openspatial pointer sent as a byte
 *  array. The function will return an array containing useful
 *  values from the openspatial pointer
 *
 *  The decode2DPOSPointer method returns a dictionary containing keys:
 *      "x" = x coordinate
 *      "y" = y coordinate
 *
 *  The decode3DTransPointer method returns a dictionary containing keys:
 *      "x" = x translation value
 *      "y" = y translation value
 *      "z" = z translation value
 *      "pitch" = pitch value
 *      "roll" = roll value
 *      "yaw" = yaw value
 * 
 *  The decodeGestPointer method retuns a dictionary containing keys:
 *      "gest" = gesture op code (determines the gesture type)
 *      "data" = gesture data
 *
 *      op code values are listed below in the format G_OP_XXXXXX
 *      gesture values are listed below op codes
 *
 *  The decodeButtonPointer method returns dictionary containing keys:
 *      "touch0" = the value of touch0
 *      "touch1" = the value of touch1
 *      "touch2" = the value of touch2
 *      "tactile0" = the value of tactile0
 *      "tactile1" = the value of tactile1
 *
 *      touch values are defined in BUTTON_UNUSED, BUTTON_UP, BUTTON_DOWN
 *
 *  The create values are used to create a pointer to data for
 *  either 2D, 3D, Buttons, or Gestures. The bytes reffered to by
 *  the pointer are formatted according to the Open Spatial specification
 */

#import <Foundation/Foundation.h>
#import "OpenSpatialData.h"
#import "OpenSpatialConstants.h"

@interface OpenSpatialDecoder : NSObject

/*!
 Decode oData returns an array of dictionaries, which will contain
 each event packed into oData, each dictionary will have a "type" key
 to determine the type;
 */
+(NSArray*) decodeODataPointer:(const uint8_t *)opSpcPtr length:(int) length;
@end